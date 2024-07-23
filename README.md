# u-blox GNSS Receiver Setup for RaceChrono Pro

This guide will help you configure your u-blox GNSS receiver to work perfectly with RaceChrono Pro.

## What You Need

- u-blox GNSS receiver
- u-center software from u-blox
- RaceChrono Pro app

## Let's Get Started

### 1. Install u-center Software

First, download and install the u-center software from the [u-blox website](https://www.u-blox.com/en/product/u-center).

### 2. Connect Your GNSS Receiver

1. Open u-center.
2. Connect your GNSS receiver to your computer via USB or another interface.
3. In u-center, go to `Receiver > Connection` and pick the right COM port to connect.

### 3. Set Baud Rate to 115200

1. Go to `View > Configuration View` (or press F9).
2. Select `PRT (Ports)`.
3. Set the baud rate to `115200` for the relevant interface.
4. Click `Send` to apply.
5. **Note**: Changing the baud rate will disconnect your receiver. You'll need to reconnect using the new baud rate. Go to `Receiver > Connection` and select the appropriate COM port with the baud rate set to `115200`.

### 4. Switch to Automotive Mode/Profile

1. In the Configuration View panel, select `CFG (Configuration)`.
2. Choose `Dynamic Model`.
3. Set it to `Automotive`.
4. Click `Send`.

### 5. Disable Other GNSS Constellations

1. In the Configuration View panel, find `GNSS Configuration`.
2. Turn off all constellations except for `GPS`.
3. Click `Send`.

### 6. Set Update Rate to 100ms (10 Hz)

1. In the Configuration View panel, go to `RATE (Rates)`.
2. Set the Measurement Period to `100 ms` (10 Hz).
3. Click `Send`.

### 7. Turn Off Unnecessary NMEA Sentences

1. In the Configuration View panel, go to `MSG (Messages)`.
2. Turn off these sentences by setting their rates to `0` for all interfaces:
   - `NMEA-GLL` (Geographic Position - Latitude/Longitude)
   - `NMEA-TXT` (Text Transmission)
   - `NMEA-GPVLW` (Distance Traveled through the Water)
   - `NMEA-GPZDA` (Date & Time)
   - `NMEA-GPGBS` (GNSS Satellite Fault Detection)
   - `NMEA-GPDTM` (Datum Reference)
   - `NMEA-GNS` (GNSS Fix Data)
   - `NMEA-GRS` (GNSS Range Residuals)
   - `NMEA-GLGSV` (GLONASS Satellites in View)
   - `NMEA-GQGSV` (QZSS Satellites in View)
   - `NMEA-GST` (GPS Pseudorange Noise Statistics)
   - `UBX-PUBX` (u-blox Proprietary Messages)
3. Make sure these essential ones are on:
   - `NMEA-GGA` (Global Positioning System Fix Data)
   - `NMEA-RMC` (Recommended Minimum Navigation Information)
   - `NMEA-VTG` (Course Over Ground and Ground Speed)
   - `NMEA-GSV` (GNSS Satellites in View)
4. **Optional**: Enable `NMEA-GSA` (GNSS DOP and Active Satellites) for additional data in RaceChrono Pro.
5. Click `Send` to apply each setting.

### 8. Save Your Settings

1. In the Configuration View panel, select `CFG (Configuration)`.
2. Choose `Save current configuration`.
3. Click `Send` to save.

### 9. Double-Check Everything

1. In u-center, open the `Text Console` window by going to `View > Text Console`.
2. Check the NMEA data output to make sure you only see the enabled sentences (GGA, RMC, VTG, GSV, optionally GSA).

## Summary

Your u-blox GNSS receiver should now be all set up for RaceChrono Pro, giving you fast and accurate data updates.

### Important Note

Consider buying an M10 GPS receiver as they are roughly 25,000₩. The M10 offers several improvements over the M8, including better sensitivity, faster acquisition times, and lower power consumption.

### M8 vs M10 Summary

- **M8**:
  - Older generation
  - Decent performance for general use
  - Lower cost

- **M10**:
  - Newer generation
  - Improved sensitivity and acquisition times
  - Lower power consumption
  - Slightly higher cost

### Ongoing Experiments

I'm currently experimenting with using more than just GPS, such as integrating GLONASS. However, currently using GPS only is best due to what seems to be a bandwidth issue when using more than one GNSS constellation. More updates will follow as experiments progress.

For more details, check out the [u-blox documentation](https://www.u-blox.com/en/docs).
