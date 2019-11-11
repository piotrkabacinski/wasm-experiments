all: sha256

sha256:
	@echo "Compiling \"hash\" example..."
	@cd hash && sh ./build.sh
	@echo "Yay! 🎉"

createZip:
	@echo "Compiling \"zip\" example..."
	@cd zip && sh ./build.sh
	@echo "Yay! 🎉"
