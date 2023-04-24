FROM ubuntu AS builder

RUN apt update -y && apt install -y clang cmake git

WORKDIR /
ADD . .
#RUN git clone https://github.com/google/fuzztest.git
RUN mkdir /build
WORKDIR /build
RUN CC=clang CXX=clang++ cmake -DCMAKE_BUILD_TYPE=RelWithDebug -DFUZZTEST_COMPATIBILITY_MODE=libfuzzer ..
RUN cmake --build .

FROM ubuntu
COPY --from=builder /build/fuzztest_calculator_cmake /fuzztest_calculator
