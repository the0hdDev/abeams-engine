# Contributing to BEAMS

We're thrilled you're interested in contributing to the Agent-Based Economy and Market Simulation (BEAMS) Engine! Your help is invaluable in making this project a success.

## How to Contribute

There are many ways you can contribute to BEAMS, even if you're not a seasoned developer or don't know C++:

### Don't know C++? No Problem!

You can always contribute to the [Frontend](https://github.com/the0hdDev/beams-frontend). The frontend is built with Electron and offers a great way to get involved without diving into the C++ backend.

### 1. Code Contributions

If you're a developer, you can contribute by:

* **Reporting Bugs:** If you find a bug, please open an issue on our [GitHub Issues page](https://github.com/the0hdDev/beams-engine/issues). Provide a clear description of the bug, steps to reproduce it, and your environment details.
* **Implementing Features:** Check our existing issues for features marked as "help wanted" or "good first issue." Feel free to suggest new features by opening an issue as well.
* **Writing Tests:** Help us ensure the stability and correctness of the code by writing unit or integration tests.
* **Code Reviews:** Review pull requests from other contributors to help maintain code quality.

---

### Platform Independence

This project is currently only compilable on macOS and Linux. We're going to add Windows support as soon as possible by moving away from raw POSIX-Sockets to standard RESTful APIs. This will allow for better debugging and temporary platform independence. While full native Windows support isn't a primary target for our main development team in the immediate future, we welcome contributions in this area!

Currently, not having native Windows support isn't critical. The console application can be run within Windows Subsystem for Linux ([WSL](https://learn.microsoft.com/en-us/windows/wsl/install)) or with [MSYS2](https://www.msys2.org/). However, native Windows support would certainly be a nice addition.

#### Pull Request Guidelines:

1.  **Fork the repository** and create your branch from `main`.
2.  **Ensure your code adheres to our coding style.** (We'll establish clear style guidelines as the project grows.)
3.  **Write clear, concise commit messages** explaining your changes.
4.  **Open a pull request** to the `main` branch of the BEAMS repository.
5.  **Describe your changes thoroughly** in the pull request description.
6.  **Ensure all tests pass** before submitting your pull request.

### 2. Documentation

Good documentation is crucial for any complex project. You can help by:

* Improving existing documentation for clarity and accuracy.
* Writing new documentation for features, installation guides, or tutorials.
* Translating documentation into other languages (if applicable in the future).

### 3. Feedback and Ideas

Even if you don't write code, your insights are valuable:

* **Provide feedback** on existing features and the overall design.
* **Suggest new features or improvements** by opening an issue.
* **Participate in discussions** on our Discord channel.

### 4. Community Support

Help others by:

* Answering questions from other users on Discord or GitHub.
* Sharing your experiences with BEAMS.

---

## Getting Started

1.  **Fork the BEAMS engine repository:** [https://github.com/the0hdDev/beams-engine](https://github.com/the0hdDev/beams-engine)
2.  **Clone your forked repository:**
    ```bash
    git clone [https://github.com/YOUR_GITHUB_USERNAME/beams-engine.git](https://github.com/YOUR_GITHUB_USERNAME/beams-engine.git)
    cd beams-engine
    ```
    *(Remember to replace `YOUR_GITHUB_USERNAME` with your actual GitHub username.)*
3.  **Set up your development environment.** Details will be provided in the main repository's `README.md` for the backend. For the frontend, refer to its [README.md](https://github.com/the0hdDev/beams-frontend/blob/main/README.md).
4.  **Create a new branch** for your contributions:
    ```bash
    git checkout -b feature/your-feature-name
    ```
    or
    ```bash
    git checkout -b bugfix/your-bug-description
    ```
5.  **Make your changes.**
6.  **Commit your changes** with a clear and descriptive message.
7.  **Push your branch** to your forked repository.
8.  **Open a Pull Request** against the `main` branch of the original BEAMS repository.

---

## Code of Conduct

We aim to foster an open and welcoming environment. Please review and adhere to our (forthcoming) Code of Conduct in all interactions.

Thank you for helping us build BEAMS!
