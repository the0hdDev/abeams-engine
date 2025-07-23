# Base image with CMake and build tools
FROM ubuntu:24.04

# Install system dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    make \
    git \
    curl \
    zip \
    unzip \
    tar \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy project files
COPY . .

# Clone vcpkg and install dependencies
RUN git clone https://github.com/microsoft/vcpkg && \
    cd vcpkg && \
    sh bootstrap-vcpkg.sh && \
    ./vcpkg install fmt nlohmann-json spdlog boost-beast boost-asio && \
    cd ..

# Create build directory, compile project
RUN mkdir -p build && cd build && \
    cmake .. && \
    make

# Create configuration file
RUN echo '\
{\n\
  "general": {\n\
    "communication": {\n\
      "port": 4000\n\
    },\n\
    "logging": {\n\
      "logLevel": 5\n\
    }\n\
  }\n\
}' > conf.json

EXPOSE 3405

# Create log directory and default log file
RUN mkdir -p log && touch log/default.log

# Start the compiled binary "main" by default
CMD ["./build/engine"]