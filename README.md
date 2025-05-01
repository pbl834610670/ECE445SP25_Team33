# ECE445SP25 Team33 Lab Notebook
Name: Ann Luo\
NetID: hluo12

## 04/29/2025
We had our final demo today. In the morning, before the demonstration, we tested our robot car one last time and made a slight adjustment to the code by modifying a condition statement to better ensure the robot wouldn't fall off the table. We also gathered some dust from room 2070 to use during the demo and show the cleaning functionality. During the demo, one of our power supply wires broke, but we were able to quickly repair it and continue. In the end, we successfully completed the final demonstration. Additionally, we recorded a video of our table-cleaning robot as part of our preparation for the extra credit submission.
![c3ad040ac136d7016f6a1cf2fd1eda6](https://github.com/user-attachments/assets/96299752-4722-407f-87af-fa69a3401db5)

## 04/28/2025
Tomorrow is our final demo. During testing today, I realized that the code still needed some adjustments. I spent the evening improving it, and by the end of the night, the robot was able to operate smoothly on the table surface. However, the jack port for our PCB board still hasn’t arrived, so we’ll have to wait until tomorrow morning to test whether everything works as expected.

## 04/05/2025
I worked on writing the code for the edge detection subsystem and began integrating it with the obstacle avoidance code. Further testing of the sensor readings is still needed to ensure smooth and successful integration. The logic may need to be adjusted to prevent any conflicts between the two subsystems.

## 04/01/2025
We first tested whether the voltage converter could successfully step up the voltage from 3.7V to 12V. After confirming it worked as expected, we connected one end of the converter to the battery and the other end to the vacuum fan. We then tested the functionality of the cooling fan to ensure it was able to effectively suck up dust from the table surface. In addition, we discussed the design of our robot’s base boards with the staff at the machine shop.

## 03/04/2025
We signed up for the breadboard demo today and began working on our breadboard setup. We decided to start by building the robot car itself, focusing on assembling the motors and basic movement. At the same time, we also began implementing the obstacle avoidance functionality using an ultrasonic sensor.

## 03/03/2025
Today was the first round for PCB orders, but since we haven’t completed our PCB schematic yet, we plan to submit our order during the second round instead.

## 02/26/2025
I researched different options for the components we plan to use in each subsystem of our project. For each part, I compared different models to find the most suitable choices in terms of functionality, compatibility, and cost. To ensure that all components would work well together, especially in terms of voltage and current requirements, we carefully reviewed the datasheets of each component to avoid potential problem later in the development process.
![354e995e2dbcacfa44e6cf2160314b5](https://github.com/user-attachments/assets/46cbc1c2-cc4b-4208-b290-e6adb3fe9281)

## 02/21/2025
We met to discuss the components we will use for each subsystem of our project. Initially, we planned to use a depth camera for detecting the edges of the table. However, after deciding to use only the Arduino Uno as our development board and realizing that the depth camera is relatively expensive and may not be easily compatible，we decided to switch to using ultrasonic sensors for both obstacle avoidance and edge detection. 

## 02/19/2025
We had our design review demo today. Initially, we planned to use both a Raspberry Pi and an Arduino Uno as our development boards, with each handling different functionalities. For example, we intended for the ESP32 to control the robot car’s motion, while the Raspberry Pi would handle obstacle avoidance and edge detection. However, during the demo, we received feedback suggesting that we simplify the system by using only one development board. After discussing, we decided to use Arduino Uno as our primary development board.

## 02/14/2025
Today, we worked on drafting our team contract. We established expectations and ground rules to ensure effective communication throughout the project. Additionally, we assigned specific roles and responsibilities to each team member based on their strengths and interests.

## 02/13/2025
We finished writing our project proposal. We considered the details of each subsystem involved in our design and discussed the potential components we might use. We also evaluated different development boards to find out the one that best fits our project. I created the initial visual aid to help visualize our overall design. 

![92246ff893ad7eb0628becd65d21ea5](https://github.com/user-attachments/assets/2afa7c5d-52d9-4d87-aa50-3ae9c6fe926d)
![41863a2be709c09de04f9ec003c0f94](https://github.com/user-attachments/assets/4d02a7ef-e6a6-475f-a698-08f91b930641)

## 02/11/2025
We had our first group meeting this week, during which we discussed our goals and the tasks we need to complete for the rest of the semester. It gave us a clearer understanding of the project timeline. 

## 02/02/2025
Our project proposal was approved, and we officially finalized our project topic: Table Cleaning Robot – Autonomous Elevated Surface Cleaner.

## 01/29/2025
I submitted our initial project proposal to the course web board. After receiving feedback from the professor and TA, we made revisions based on their suggestions to improve the proposal.
