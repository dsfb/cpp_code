# add your user to the docker group.
sudo su -
groupadd docker
usermod -aG docker $USER
exit

# your images and containers
docker images 
docker ps # shows you all containers that are currently running
docker ps -a # a list of all containers that we ran
docker container ls -a # all your containers

# load an image from *.tar archive
docker load --input <tar archive>
docker load < <tar archive>

# remove an image
docker image rm <image name>

# load an image from a registry
docker pull <image>

# create new a container from an image
docker run  -d --name <name>  -it <image id>  bash  # it gives an unique name for a container
docker run <image> # run some container
docker run -it <image> sh # run with terminal
docker run --rm <image> # run and delete
docker run -p <custom local port>:<container port> #specify a custom port to which the client will forward connections
-d # you can happily close your terminal and keep the container running. This is called detached mode
-P # will publish all exposed ports to random ports
--name <name> # corresponds to a name we want to give

# run the exited container
docker start <container> 
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