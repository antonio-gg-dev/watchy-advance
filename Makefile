.DEFAULT_GOAL := help
.PHONY: test

FORMAT_FILES := $(shell git ls-files --cached --others --exclude-standard -- '*.cpp' '*.h')
LINT_FLAGS := clangtidy: --config-file=.clang-tidy

test: ## Run native simulator tests
	pio test -e simulator

lint: ## Run clang-tidy on project code
	pio check -e simulator \
		--fail-on-defect=low \
		--fail-on-defect=medium \
		--fail-on-defect=high \
		--flags="$(LINT_FLAGS)"

lint/fix: ## Apply available clang-tidy fixes
	pio check -e simulator \
		--fail-on-defect=low \
		--fail-on-defect=medium \
		--fail-on-defect=high \
		--flags="$(LINT_FLAGS) --fix"

format: ## Check project C++ formatting
	clang-format --dry-run --Werror $(FORMAT_FILES)

format/fix: ## Apply clang-format fixes
	clang-format -i $(FORMAT_FILES)

all/fix: ## Apply clang-tidy and clang-format fixes
	$(MAKE) lint/fix
	$(MAKE) format/fix

build/simulator: ## Build the simulator environment
	pio run -e simulator

build/watchy: ## Build the Watchy V3 environment
	pio run -e watchy-v3

pre-commit: ## Run pre-commit checks
	$(MAKE) --no-print-directory format
	$(MAKE) --no-print-directory lint
	$(MAKE) --no-print-directory test
	$(MAKE) --no-print-directory build/simulator
	$(MAKE) --no-print-directory build/watchy

pre-commit/install: ## Install Git pre-commit hook
	@echo '#!/bin/sh\nmake pre-commit' > .git/hooks/pre-commit
	@chmod +x .git/hooks/pre-commit

help: ## Show this help message
	@echo 'usage: make [target]'
	@echo
	@echo 'targets:'
	@grep -E '^[a-zA-Z0-9_./-]+:.*## ' $(MAKEFILE_LIST) | \
		awk 'BEGIN {FS = ":.*## "}; {printf "  %-18s %s\n", $$1, $$2}'
