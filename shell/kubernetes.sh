INFORMATION
kubectl -n <namespace> get pods # get list of my pods
kubectl get all -o wide
kubectl get pods -n <namespace> <pod> --watch # watching a pod

COPY
# first you shoud copy a file to /tmp/ directory and then move it somewhere
kubectl cp <file name> <namspace>/<pod name>:/tmp/ -c <container name if needed> 
&& echo "the result is $?"

SIGN IN TO A POD OR CONTAINER
kubectl -n <namespace> exec -it <pod name> bash # sudo is required
docker ps | grep <what you are looking for>
docker exec -u root -it <container> bash # sign in like a root user

LOG
kubectl logs -n <namespace> <pod name> --since=2m > log.txt
docker logs -n <namespace> <pod name> --since=2m > log.txt

DEPLOYMENT HISTORY AND ROLL BACK
helm list | grep <service name>
helm history  <pod name>
helm rollback <service name> <revision>

UPGRADE
helm upgrade <service name> <path to chart>

UNSORTED
kubectl delete pod -n <namespace> <pod name>

