This is a program that uses OpenGL to draw three oxeye daisy plants inside a rectangular pot complete with leaves, brown soil, green plains, blue sky, clouds and the sun, all in 3D. When the program starts, the user is greeted with the flower pot in front of them, the daisy plants slowly emerging from the soil, growing into full plants. The user can control the camera using their mouse and move around with WASD or the arrow keys. The user can also control the sun’s position using the J and K keys. The user can enable automatic daylight cycle effect using the M key. The users can reset the blooming effect (which is the growing of daisy flowers from the soil) using the R key.
In this project, we applied lots of graphics effects on the flowerpot, flower, leaves and even on the environment itself. 
We now highlight some notable effects and features that we have added:

The sun
We modelled the sun as our main directional light source in this project. All objects will undergo a light shading effect when there is sunlight. Other than that, users can control the sunlight angle by pressing J or K keys, and the light shading effect will adjust accordingly, reflecting the sun’s position.

Daylight cycle effect
When the sun goes below the horizon, it turns into nighttime. The daylight effect we apply here is the same as the daylight in our real life. The sunlight will become dimmer when it is approximately night time.

Wind effect 
We also applied the wind swaying effect on our flower. That is, the flower will subtly sway left and right like there’s wind. We did this to simulate real-life plants swaying left and right due to wind. This is because, in the real world there is actually wind that will cause the flower to sway left and right. Therefore, to actually implement the wind effect that results in swaying of the flower, we actually implement an algorithm applying some quite some mathematics knowledge to let the swaying effect be more natural. 

Sky effect 
The sky effect we applied in the project also illustrate the real life sky effect. From morning to evening, the sky will constantly be blue in color to illustrate the blue sky, however, when close to night time, the sky will gradually become darker and darker in colour and lastly become black in color that represents night. 

Blooming effect of flower 
We also apply the blooming effect of flowers to illustrate the growing process of the flower.



Leaf growing position 
One of the details we provided in this project is everytime we run the project, the leaf position would be different as we had included a randomized leaf position on the flower, so that each flower can have different looks and be more natural. From the illustration below, we can see that the leaf position is different every time we run the program.



Camera effect
Users can have full control of the camera position with the combination of  “WASD” or arrow keys with the mouse. User can ascend the camera using <space> key and descend using <shift> key.
