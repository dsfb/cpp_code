# your images and containers
docker images 
docker ps # shows you all containers that are currently running
docker ps -a # a list of all containers that we ran

# load from registry
docker pull <image>

# load from *.tar archive
docker load --input <tar archive>
docker load < <tar archive>

docker run <image> # run some image
docker run -it $1 sh # run with terminal
docker run --rm <container> # run and delete
-d # you can happily close your terminal and keep the container running. This is called detached mode
-P # will publish all exposed ports to random ports
--name # corresponds to a name we want to give
docker start <container> # run the exited container
docker run -p <custom local port>:<container port> #specify a custom port to which the client will forward connections
docker stop <id> # To stop a detached container
docker rm <container id> # stop the container
docker rm $(docker ps -a -q -f status=exited)
-f # filters output
docker rm # delete

docker port <container> # shows open ports of a container
docker search # ???

Dockerfile #  a list of commands that the Docker client calls while creating an image
docker build . # build  here
-t <name> # to specify a cusnom name for uor own image
--file # specifies costom file name

docker image history --no-trunc image_name > image_history # build history


docker commit <container> <new image name>
docker exec -it <container> <command like /bin/bash/> # run shell inside runned image