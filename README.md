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
<h3>Heater controll schematic</h3>

<img width="803" height="630" alt="image" src="https://github.com/user-attachments/assets/71ffbd76-8f08-44c6-9fd2-6f43f3506a3e" />

<h3>Other parts</h3>

I also made a ntc thermistor thermometer by using it in a voltage divider configuration and reading the voltage using an arduino analog pin.

<h2>Component links</h2>

- PTC heater: https://www.aliexpress.com/item/1005007442989854.html?spm=a2g0o.order_list.order_list_main.103.4dad1802Yx2w8E
- LCD screen: https://www.aliexpress.com/item/1005006151355330.html?spm=a2g0o.order_list.order_list_main.78.4dad1802Yx2w8E
I used an encoder from the arduino starter kit, the CH340 arduino nano and parts I had laying around

<h2>Design conciderations</h2>

- make sure the PSU power rating is at least 15% higher than the Heater power
- use a microcontroler that has analog interrupt pins to detect encoder movements
