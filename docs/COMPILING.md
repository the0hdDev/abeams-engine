# Building and Running ABeams with Docker

This document describes how to compile and run the ABeams-Engine using Docker.

## Requirements

- Docker
- Git

## Clone the Repository

```bash
  git clone https://github.com/the0hdDev/beams-engine
  cd beams-engine
```

## Build the Docker Image

```bash
  docker build -t beams-engine .
```

This will:
- Clone and bootstrap vcpkg
- Install required dependencies (boost-beast, boost-asio, fmt, spdlog)
- Configure and build the project using CMake
- Create a `conf.json` and a `log/default.log` inside the container

## Run the Container

```bash
  docker run -p 3405:3405 beams-engine
```

This will start the compiled binary and expose port `3405` for WebSocket communication.

## Mounting Configuration and Log Files (Optional)

To use a custom configuration or persist log files, use volume mounts:

```bash
  docker run -p 3405:3405 \
    -v $(pwd)/conf.json:/app/conf.json \
    -v $(pwd)/log:/app/log \
    ABeams-engine
```

## Output

- The compiled binary is located in `/app/build` inside the container.
- Logs are written to `/app/log/default.log`.

## Rebuilding After Code Changes

```bash
  docker build --no-cache -t beams-engine .
```

## Troubleshooting

If you encounter any issues, please refer to the Issues page:
https://github.com/the0hdDev/abeams-engine/issues
