Usage:

example_bricker_i2c.vi contains an example on how to use bricker_arduino_i2c.vi in an existing LabVIEW project. It is important to use a "stop" button as demonstrated to maintain control of the device.


The arduino is set up to detect configuration changes (number of sensors present and what position they are installed in) automatically, as seen below. The VI outputs an array of 6 pressure strings and 6 temperature strings. 
![image](https://user-images.githubusercontent.com/59129127/196773149-0dd5ab31-4ed0-489c-84a9-5237b239227c.png)
![image](https://user-images.githubusercontent.com/59129127/196773199-d709c47c-b5e6-4b5f-b0fa-5fc8dc8eb8d4.png)
