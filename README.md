# ECE445SP25 Team33 Lab Notebook
Name: Ann Luo\
NetID: hluo12

## 04/29/2025
We had our final demo today. In the morning, before the demonstration, we tested our robot car one last time and made a slight adjustment to the code by modifying a condition statement to better ensure the robot wouldn't fall off the table. We also gathered some dust from room 2070 to use during the demo and show the cleaning functionality. During the demo, one of our power supply wires broke, but we were able to quickly repair it and continue. In the end, we successfully completed the final demonstration. Additionally, we recorded a video of our table-cleaning robot as part of our preparation for the extra credit submission.
![c3ad040ac136d7016f6a1cf2fd1eda6](https://github.com/user-attachments/assets/96299752-4722-407f-87af-fa69a3401db5)


## 04/28/2025
Tomorrow is our final demo. During testing today, I realized that the code still needed some adjustments. I spent the evening improving it, and by the end of the night, the robot was able to operate smoothly on the table surface. However, the jack port for our PCB board still hasn’t arrived, so we’ll have to wait until tomorrow morning to test whether everything works as expected.

## 04/16/2025
The machine shop finished building our robot car model and delivered it to us. However, the model turned out to be much larger than we expected. The most significant issue is that the width of the robot car is too wide—it greatly exceeds the coverage area of our vacuum fan. As a result, the cleaning subsystem cannot effectively cover the surface as the robot moves. To address this problem, I decided to create a new model that better fits the dimensions required for efficient cleaning.
![b35b8bb017a6796984d776e2eb9a51c](https://github.com/user-attachments/assets/f7692edc-ee05-4916-a949-4f35a4ce09da)


## 04/08/2025
I’m still working on combining the obstacle avoidance and edge detection code to ensure both subsystems function smoothly together. After testing, I decided to switch from ultrasonic sensors to IR sensors for the edge detection subsystem, as IR sensors have faster response times and greater accuracy for detecting table edges. I ordered the IR sensors online and will begin assembling them on the robot car once they arrive.
![18e6504bf972bf29fbf9c03f840ba11](https://github.com/user-attachments/assets/bfded471-f034-4664-817f-9fe27c88793b)

## 04/05/2025
I worked on writing the code for the edge detection subsystem and began integrating it with the obstacle avoidance code. Further testing of the sensor readings is still needed to ensure smooth and successful integration. The logic may need to be adjusted to prevent any conflicts between the two subsystems.

## 04/02/2025
I completed the individual progress report today. In the report, I included a flow diagram that outlines the logic we plan to implement for our table-cleaning robot. Since one of our main goals is to ensure the robot can effectively cover the entire table surface, the diagram illustrates the detailed decision-making process and movement logic of our robot car.
![2a904211518edb4d506f31b6b6bcaa9](https://github.com/user-attachments/assets/580f05fd-47f0-49ef-9f1e-832b8d0e2bac)
![50caa8d2303a3a2d6351cff5be0d8a7](https://github.com/user-attachments/assets/4d2d3261-adfe-42db-bf70-556989225f4c)
![5c395bb8cbe6518b622b654fadf03dc](https://github.com/user-attachments/assets/dbea249e-0ce0-47e8-bd39-7c6b9eb0b0a9)


## 04/01/2025
We first tested whether the voltage converter could successfully step up the voltage from 3.7V to 12V. After confirming it worked as expected, we connected one end of the converter to the battery and the other end to the vacuum fan. We then tested the functionality of the cooling fan to ensure it was able to effectively suck up dust from the table surface. In addition, we discussed the design of our robot’s base boards with the staff at the machine shop.

![53b5ac126a8ba9f1cceaa6f1c0ef8f8](https://github.com/user-attachments/assets/38aa8087-5397-4762-89d4-8078bfb12500)


## 03/31/2025
We didn't place a PCB order during the third round due to issues we encountered while soldering our current board. Some of the pins were too closely spaced, which caused solder bridges and led to a short circuit on the board. Our team decided to focus on fixing this issue first.

## 03/26/2025
We assembled the electronic components for the obstacle avoidance subsystem and tested the code to verify its functionality. The system appears to be working well so far, but further adjustments may be necessary. This is because we still need to finalize and communicate our specific design requirements for the robot car to the machine shop, and wait for them to complete the final robot car model.
![f504946d85a7066cae9dc6acd1520a3](https://github.com/user-attachments/assets/7a60ce7d-d1e8-47e1-a349-047005028049)


## 03/25/2025
I spent time researching various vacuum fan options for our debris collection subsystem, but most of them were unsuitable due to issues with voltage, size, or other limitations. After comparing several alternatives, I found a 12V computer cooling fan that might work for our needs and decided to purchase it for testing. Since our battery only supplies 3.7V, I also bought a voltage converter to ensure the fan receives the required power. Additionally, as we plan to solder our PCB in the coming days, I purchased soldering paste.
![af3d66f9ac77a96362a5bcd1abf75d4](https://github.com/user-attachments/assets/ac4ef819-c02a-4c25-818c-7b0c88bab1f7)


## 03/14/2025
We discussed our design with the machine shop and brought up the idea of incorporating a robotic arm into our obstacle avoidance subsystem. The goal was to lift objects and clean the area underneath them. However, they advised us against implementing this feature due to its complexity and feasibility. As a result, we decided to simplify the design and focus on detecting and avoiding obstacles.

## 03/13/2025
Today was the deadline for the second round of PCB orders. Initially, the machine shop informed us that the files we submitted were incomplete. However, I was able to send the correct and complete files just in time, and they were successfully accepted. As a result, we were able to place our PCB order before the deadline.

## 03/11/2025
We had our breadboard demo today. During the demo, we were able to demonstrate that our obstacle detection system works as intended. However, I realized that the presentation could have been more effective if we had connected the obstacle detection system directly to the robot car. This would have allowed us to better show how the robot responds to obstacles in real time, providing a clearer picture of the subsystem’s functionality.

## 03/10/2025
We now have a clear understanding of our circuit design. We successfully measured the distance between obstacles and our ultrasonic sensor and displayed the readings on the Arduino Uno serial monitor. However, since we are still in the process of assembling the system and want to avoid soldering wires directly onto our L293D motor driver at this stage, we decided not to connect the motors and ultrasonic sensor together.

## 03/06/2025
We completed the design document today, including finalizing the RV table and updating the visual aid. One of the major changes we made was replacing the depth camera with an ultrasonic sensor for obstacle avoidance, due to cost and compatibility concerns. Additionally, we switched our development board from the Raspberry Pi to the Arduino Uno to simplify our system. For the debris collection subsystem, we are still in the process of selecting a suitable vacuum fan. For now, we’ve included a 12V DC mini vacuum fan as a placeholder in the visual aid, but further research and testing are needed. We also updated our block diagram to ensure it accurately represents our current system design.
![f44b8bc611ab4006bd9b1bf04e2af41](https://github.com/user-attachments/assets/600d8142-6a10-4b4d-bce8-b72e63fb91fd)
![299f2aa982a2e6d1f79a8758fba2927](https://github.com/user-attachments/assets/c6a17014-1d42-40eb-bfc1-688750ee3ccd)


## 03/05/2025
I completed the teamwork evaluation today and continued working on assembling the breadboard. I focused on connecting the key components and verifying that the basic circuits function correctly.

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
