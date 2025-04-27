Miniature Home control

Maker 2024-2025 - Miniature Home control
========================================

Project overview

Introduction
------------

This project was carried out as part of the Maker option at ENSEA. The idea was to create a miniature home that could house a small animal with a bunch of actuated parts  
(doors, lights, food dispenser...) that could be activated remotely.  
Design-wise the house is inspired by typical doll house designs and modern houses:

![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/screen.png)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/screen1.png)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/screen2.png)

  

Below is the architectural diagram that sums up all the features that were to be included in the house at the start of the project:![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745759258063.png)

CAD
---

This project involved a lot of CAD. A significant part was the modeling of the whole house. The goal was to make the house out of wood using the laser cutter.  
Thus the model needed to be able to be separated in several parts to be cut on a flat sheet

![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745758736926.png)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745758788668.png)

All the furnitures to be placed in the house were also 3D modeled by myself (except the chair I downloaded it online). They were then 3D printed.

![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745759042001.png)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745759064490.png)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/20250411_175810_wMgNOAr.jpg)

  

PCB
---

Every PCBs in this project were designed on KiCAD and manufactured by JLCPCB.  
This project needed two PCBs: one main unit would be wired to every actuatable parts in the house.  
Thus, it is mainly comprised of sockets to wire to every motors, lights, TV...

![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745760197331.png)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745760786155.jpeg)

  

The second PCB is the controller of the house to actuate remotely every part of the house. Thus it is mainly comprised of buttons to look like a run-of-the-mill remote:

![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745761047043.jpeg)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745761053683.jpeg)

Assembly
--------

After laser cutting the wood the house was assembled, some furnitures were also placed inside:

![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/20250411_180402.jpg)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745761537156.png)

  

The assembly part also involved a lot of wiring. I made custom wires for the power supply to power the main unit, a LiPo battery for the controller  
and several wires for motors and lights in the house:

![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/mieux.png)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745762384618.png)![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745762737792.png)

  

Programming
-----------

The code was written  in C language on STM32 CubeIDE. It is devised according to this diagram:

![](http://maker.coventgarden.fr/media/uploads/froala_editor/images/1745763220026.png)

I wrote a working code for the LCD screen (for the TV), servo motors, Neopixel LEDs and the MP3 module. I did not have time to test the code for the HC-05 bluetooth module.  
The whole code can be found in the GitHub repository (as well as every other resources of the project)

Final word
----------

I did not have the time to finish the project so only the house, the PCBs and the lights and doors are implemented but I still had a great time doing this project and participating in Maker.

### Short video

Here is a short video (in French) to sum up the project and my views on the Maker option
[![Watch the video](https://www.youtube.com/watch?v=WIeOZKU2mvY&t=1s)
