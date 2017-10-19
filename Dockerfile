FROM gcc:4.9

LABEL io.resin.device-type="beaglebone-green-wifi"

RUN apt-get update && apt-get install -y --no-install-recommends \
		less \
		kmod \
		nano \
		net-tools \
		ifupdown \	
		iputils-ping \	
		i2c-tools \
		usbutils \
		wget \		
	&& rm -rf /var/lib/apt/lists/*

RUN echo "deb [arch=armhf] http://repos.rcn-ee.net/debian/ jessie main" >> /etc/apt/sources.list

RUN apt-key adv --keyserver keyserver.ubuntu.com --recv-key D284E608A4C46402

COPY ./hello/* /hello
# COPY . /hello
WORKDIR /hello
RUN gcc -o hello1 hello.c
CMD ["./hello1"]