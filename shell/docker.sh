# add your user to the docker group.
sudo su -
groupadd docker
usermod -aG docker <user name>
exit

docker images # it lists your images
docker ps # shows you all containers that are currently running
docker ps -a # a list of all containers that we ran
docker container ls -a # all your containers
docker image rm <image name> # remove an image
docker pull <image> # load an image from a registry
docker cp <from> <to>:/tmp/ # it copies files to or from the active container
docker exec -it <container name> <command> # it executes a command inside container

# to load an image from *.tar archive
docker load --input <tar archive>
docker load < <tar archive>

# to create new a container from an image
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

docker port <container> # shows open ports of a container
docker search # ???

Dockerfile #  a list of commands that the Docker client calls while creating an image
docker build . # build  here
-t <name> # to specify a cusnom name for uor own image
--file # specifies costom file name


# to build the image with files in current directory
docker build --file <file name>.dockerfile  . > log
docker commit <container> <new image name>
docker exec -it <container> <command like /bin/bash/> # run shell inside runned image
docker image history --no-trunc image_name > image_history # build history




Commands:
  attach      Attach local standard input, output, and error streams to a running container
  build       Build an image from a Dockerfile
  commit      Create a new image from a container's changes
  cp          Copy files/folders between a container and the local filesystem
  create      Create a new container
  diff        Inspect changes to files or directories on a container's filesystem
  events      Get real time events from the server
  exec        Run a command in a running container
  export      Export a container's filesystem as a tar archive
  history     Show the history of an image
  images      List images
  import      Import the contents from a tarball to create a filesystem image
  info        Display system-wide information
  inspect     Return low-level information on Docker objects
  kill        Kill one or more running containers
  load        Load an image from a tar archive or STDIN
  login       Log in to a Docker registry
  logout      Log out from a Docker registry
  logs        Fetch the logs of a container
  pause       Pause all processes within one or more containers
  port        List port mappings or a specific mapping for the container
  ps          List containers
  pull        Pull an image or a repository from a registry
  push        Push an image or a repository to a registry
  rename      Rename a container
  restart     Restart one or more containers
  rm          Remove one or more containers
  rmi         Remove one or more images
  run         Run a command in a new container
  save        Save one or more images to a tar archive (streamed to STDOUT by default)
  search      Search the Docker Hub for images
  start       Start one or more stopped containers
  stats       Display a live stream of container(s) resource usage statistics
  stop        Stop one or more running containers
  tag         Create a tag TARGET_IMAGE that refers to SOURCE_IMAGE
  top         Display the running processes of a container
  unpause     Unpause all processes within one or more containers
  update      Update configuration of one or more containers
  version     Show the Docker version information
  wait        Block until one or more containers stop, then print their exit codes
