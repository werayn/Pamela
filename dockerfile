FROM debian:stretch

# Install compilation requirements
RUN apt-get update && apt-get -y install make gcc libpam-dev libgpgme11 libssl-dev libcryptsetup-dev

# Add 2 default users
RUN useradd -m -g users -s /bin/bash toto && useradd -m -g users -s /bin/bash tata

# Copy and move into project root
ADD . /usr/src/pamela_epitech
WORKDIR /usr/src/pamela_epitech

# Compile & install
RUN make && make install
