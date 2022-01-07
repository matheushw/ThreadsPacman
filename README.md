## Students
Matheus Barcellos de Castro Cunha - Nº USP -> 11208238
Alexandre Lima Palles Rocha - Nº USP -> 11797038
Alexandre Brito Gomes - Nº USP -> 11857323

# Threads Pacman

<p align="center">
  <img src="https://user-images.githubusercontent.com/55332784/148470423-472069af-a9ba-4996-8936-b563e90cd838.png" width=50% height=50%>
</p>

Threads Pacman is a simplified version of the famous game Pacman, made with threads and semaphores. It was meant to be developed as a collaborative programming
exercise in a course for the subject "SSC0140 – Sistemas Operacionais I".

## SETUP
### Installation

To install, you can just clone this repository and run using the makefile.

```
$ make all run
```

## USAGE

### Playing the game

After running the game, your goal is to collect all the points without being touched by a ghost. There are 5 ghosts (one more than the original game) trying to kill you in the arena, so try your best to catch as more points as you can!

### Controls:
	WASD/ARROWS to control the pacman

## Semaphore usage
The semaphore implemented was a counting semaphore, however, due to its usage with counter variable equals to one, it acted like a binary semaphore, and so it guaranteed mutual exclusion. We implemented the two basic counting semaphore functions: notify and wait. The notify function will be used to tell a blocked thread that it can perform changes in the critical section (Campo's instance) at the moment. The wait function is used to block thread execution until it receives a notification telling that the critical section (Campo's instance) is safe to be accessed.

## Threads usage
After instantiating the ghosts and Pacman objects, the game is creating threads using the created objects' main lambda functions. All the implemented thread functions worked in loops, so they could execute the same routine every time they are able to deal with the critical section. During their time being able to access the critical section, the threads accessed and changed the same instance of the "Campo" object, which stores the game map, as so as a variable that indicates if the game is over, so every thread can know when to stop looping.