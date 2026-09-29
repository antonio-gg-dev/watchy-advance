# Contributing to Watchy Advance

## Development requirements

- [PlatformIO Core](https://docs.platformio.org/en/latest/core/installation/index.html)
- [GNU Make](https://www.gnu.org/software/make/manual/make.html)
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html)

## Getting started

After cloning the repository:

1. Enter the project directory.
2. Install the local pre-commit hook with `make pre-commit/install`.

This installs the local quality gate that runs before each commit.

## Development workflow

Run `make help` to see the available development commands.

The project is developed using TDD. Keep changes small and focused. Commit messages follow [Conventional Commits](https://www.conventionalcommits.org/).
