# filament-dryer
A simple and cheap filament dryer made from a paint bucket and budget components

<img width="803" height="630" alt="image" src="https://blueprint.hackclub.com/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTg1OTgsInB1ciI6ImJsb2JfaWQifX0=--5030ea12f698479bd8072d8cd7ae0a92c5868abf/IMG_20251204_205554.jpg" />

<h2>Components</h2>

- An Arduino nano
- PTC heater
- paint bucket
- 12V PSU
- an LCD display
- rotary encoder

<h2>Schematics</h2>
<h3>main schematic</h3>

<img width="2039" height="831" alt="image" src="https://github.com/user-attachments/assets/d818a36e-b304-43ff-ada7-ca14ccd09a26" />

this circuit excludes the fan and the rotary encoder however they are simple to wire up. the fan is connecter to GND and +12V, and the encoder wiring diagram can be found in multiple tutorials


<h3>originall heater circuit</h3>
<img width="871" height="835" alt="image" src="https://github.com/user-attachments/assets/bd97ec19-10e6-4eda-bfc2-7c879244ba46" />


<h3>Other parts</h3>

I also made a ntc thermistor thermometer by using it in a voltage divider configuration and reading the voltage using an arduino analog pin.

<h2>Component links</h2>

- PTC heater: https://www.aliexpress.com/item/1005007442989854.html?spm=a2g0o.order_list.order_list_main.103.4dad1802Yx2w8E
- LCD screen: https://www.aliexpress.com/item/1005006151355330.html?spm=a2g0o.order_list.order_list_main.78.4dad1802Yx2w8E
I used an encoder from the arduino starter kit, the CH340 arduino nano and parts I had laying around

<h2>Design conciderations</h2>

- make sure the PSU power rating is at least 15% higher than the Heater power
- use a microcontroler that has analog interrupt pins to detect encoder movements

<h2>Finished Product pictures</h2>

![1000009728](https://github.com/user-attachments/assets/b4d9d813-b4e7-48a0-9672-8733a8779c8a)
![1000009724](https://github.com/user-attachments/assets/96546dd1-5d9e-42d7-a1f6-eb237fe18b41)
![1000009725](https://github.com/user-attachments/assets/6f200dad-4c49-4dff-90db-7ad5025c7c8f)
![1000009726](https://github.com/user-attachments/assets/3cdb799a-7b62-4d22-a053-db376bd6d9aa)
![1000009727](https://github.com/user-attachments/assets/4aef67d2-8195-48a8-8b0b-04c558027087)
