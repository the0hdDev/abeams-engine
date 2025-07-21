# Base image mit CMake und Build Tools
FROM ubuntu:24.04

# System-Dependencies installieren
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

# Arbeitsverzeichnis
WORKDIR /app

# Projektdateien kopieren
COPY . .

RUN git clone https://github.com/microsoft/vcpkg && cd vcpkg && sh bootstrap-vcpkg.sh && ./vcpkg install fmt nlohmann-json spdlog boost-beast boost-asio && cd ..

# Build-Verzeichnis anlegen und kompilieren
RUN mkdir -p build && cd build && \
    cmake .. && \
    make

# Konfigurationsdatei anlegen
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

# Log-Verzeichnis & Datei
RUN mkdir -p log && touch log/default.log

# Falls dein Binary z.B. "main" heißt
