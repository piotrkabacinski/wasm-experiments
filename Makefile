all: sha256 createZip

sha256:
	@echo "Compiling \"sha-256\" example..."
	@cd hash && sh ./build.sh
	@echo "Yay! 🎉"

createZip:
	@echo "Compiling \"zip\" example..."
	@cd zip && sh ./build.sh
	@echo "Yay! 🎉"
