# Pamela

## Description

Welcome !  
Pamela is pluggable authentication modules(PAM) project for unix user session.  
Of course it's a homemade project to learn more about this kind of security.  
Keep your default PAM is perfect :)  

## Getting started

### Prerequisites

#### Docker
 - Docker :
   follow the [install intructions](https://docs.docker.com/install/).
---

You can directly test it into your computer but it's not recommended ! 
To test our pamela let's use a docker container.  
In this repo you will find the correspond Dockerfile.  

So first,

```bash
git clone git@github.com:werayn/Pamela.git
```

And launch the Dockerfile :  

```bash
docker build . -t pamela && docker run -it pamela
```

You can test your PAM into the docker container now, Great ! :)

## Authors

* **Junique Virgile** - *Initial contributor* - [Junique Virgile](https://github.com/werayn)
---
