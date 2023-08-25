# OpenGLRenderer
This is a project that I am working on in order to learn graphics programing. This project was built following the online textbook: https://learnopengl.com/ . While my implementations follow closely with the textbook's examples, there are a few differences. For one I chose to abstract a cube into it's own class as well as having a world class that creates cubes and other world objects. 

![GIFMaker_me](https://github.com/dizzyj/OpenGLRenderer/assets/22693277/ee6aad50-db17-4ee7-8790-7fca4917306d)


At the moment, I can create cubes and set their coordinates in world space. Each cube uses a cubemap that can be selected with an enum. Eventually I want to implement a way to input world data such as a txt file, that makes it easier to manipulate an entire world. My reasoning for this, is that I am not sure exactly what which direction I want to go with this. My initial thoughts were to create a game engine, but that may be a bit more than I can chew at the moment. Only time will tell!
The world can create light objects. Currently the only lighting implemented is based on the Phong model. Shadows coming soon!

I think the next thing to be implemented is integrating Dear IMGUI. This would be a great way to modify values in real time while the code is running. 
