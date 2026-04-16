#taking alpine as our server has linux headers and functions in it
FROM alpine:3.19
#borrows the compiler to run also doesnt store the dowloads to make image size small
RUN apk add --no-cache g++ make
#sets the worklocation inside our app and then copies the file inside the app
WORKDIR /app
COPY . .
#use g++ output binary name is server and src code is server.cpp pthread links the thread library as we use threads
RUN g++ -o server server.cpp -pthread
#runs the compiled command when container starts
CMD ["./server"]