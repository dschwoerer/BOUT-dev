set -ex

if which podman &> /dev/null ; then
    cmd="time podman"
else
    cmd="time sudo docker"
fi

file=$1
test -f $file || file=.docker/fedora/Dockerfile.sh
shift
if test -e $file
then
    COMMIT=$(git rev-parse HEAD) bash $file $@ > Dockerfile
else
    cp $file Dockerfile
fi

$cmd build -t mobydick -f Dockerfile
for tag in $TAGS
do
    $cmd tag mobydick $REPO/$IMAGE_NAME:$tag
    $cmd push $REPO/$IMAGE_NAME:$tag
done
