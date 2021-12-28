# Crawling-Robot-with-ML


## Project Description
The main idea of the project is to use a reinforcement learning algorithm to crawl using two servo motors by randomly making actions that will eventually lead to crawling by the motors arm.

![Picture1](https://user-images.githubusercontent.com/80456446/124988035-ceacf380-e03d-11eb-82ad-f8f3c0914a18.png)


## Components

- Arduino UNO (ATMEGA328 chip)

- HC-SR04 Ultrasonic Sensor
Distance Sensor

- Servo Motor Metal Gear MG995 (11kg.cm)
Motors

- Batteries & Battery Holder
3 Batteries

- Breadboard and Jumpers

- Wheels and FreeWheel

- Manually Designed Wooden Body
Using Solidworks

## The Used Algorithms and Updates
Simplified Reinforcement:

- This is a simplified version of the reinforcement learning algorithm that will reward the robot only when movement occurs and saves the angles that made that movement then redo it.
- This is achieved by randomly making angles that will rotate the servos.

## Circuit Diagram
![Picture2](https://user-images.githubusercontent.com/80456446/124988447-47ac4b00-e03e-11eb-91ac-a2cf3c51767b.png)

## Video
https://drive.google.com/file/d/19N4vUqQpqdF3Ai1_-XjgJ74Mm5AtLkkg/view


## Arduino UNO Tinkercad Links and Codes:
1- Simplified Reinforcement Tinkercad: https://www.tinkercad.com/things/eoqhw0OoxWC-crawling-robo/editel?sharecode=HzdtLKtlDmwFJ1OhViUFuBfov0GWdnGfrsOyU3StzVI

2- Simplified Reinforcement Code: https://docs.google.com/document/d/1Hj75qofPrg2LjrBx7DJsCNUKW8Bt2k5BKDhX43kh79w/edit?usp=sharing

3- Q-learning Tinkercad: https://www.tinkercad.com/things/5R0Q1w4MCo9-crawling-robo-v2/editel?sharecode=VlUb-peb7xUSP38wDAwj9Oyc5Km9mC75Zum8tPqOZk0

4- Q-learning Code: https://docs.google.com/document/d/1urevdSyf88wsJhFH8FmC4ZJjTLFrEsnV9PTQA-yps9w/edit?usp=sharing

## How does it work
a- States Description:
The states of the robot are defined by the random angles generated to be made to control the servos to find the best angles possible to crawl in the best fashion possible.

b- Actions Description:
The actions are defined by randomly rotating the angles of each servo.
 
c- Architecture of Model:

This is a simplified version of the reinforcement learning algorithm that will reward the robot only when movement occurs and saves the angles that made that movement then redo it.

This is achieved by randomly making angles that will rotate the servos.

d- Time is taken to finish the learning or number of iterations:
Normally the number of iterations is at 20 iterations so that means that the robot takes 20 random states and learns from them, however, to improve the accuracy 40 iterations were made to achieve the optimal result.



## Pixels App 
![187960930_3955292401216930_6844533153445761662_n](https://user-images.githubusercontent.com/80456446/124113684-00392400-da6c-11eb-8779-cea0193eefb6.jpg)

“Pixels Egypt” mobile app is considered an important and easy way to stay in touch with us.

The app will help you to:

- Browse different online courses and resources in different fields like Computer, Communication, Power, and Mechanical Engineering.
- You will find courses, videos, books and more.
- Follow our news.
- Share our knowledge.
- Be one of the family.

Get it now on Google Play:

https://play.google.com/store/apps/details


## Follow Pixels:

- Facebook:

https://www.facebook.com/PixelsEgyptOrg

- YouTube:

https://www.youtube.com/c/PixelsEgypt

- Instagram:

https://www.instagram.com/pixelsegypt/

- Twitter:

https://twitter.com/pixelsegypt?lang=en


