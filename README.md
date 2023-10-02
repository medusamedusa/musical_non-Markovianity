# musical_non-Markovianity

This repo contains the original C code by [Maria Mannone](http://mariamannone.com/) to compute distribution matrices starting from musical MIDI-like parameters. These matrices can then be used to compute the coefficient of non-Markovianity, as described in the article "Characterization of the degree of Musical non-Markovianity," by M. Mannone and G. Compagno. This code was part of Mannone's MSc thesis in theoretical physics (chapter 8).

In 2023, [Omar Costa Hamido](https://omarcostahamido.com) reviewed and ported the code to [Max/MSP](https://cycling74.com). The goal was to make the code more interactive, compatible with regular MIDI files, and optimize the workflow.

<img width="1094" alt="Screen Shot 2023-05-14 at 5 28 16 PM" src="https://github.com/omarcostahamido/musical_non-Markovianity/assets/18335360/76e196f9-e566-43bf-b3f7-fc725f1c9004">

<!-- <img width="1102" alt="Screen Shot 2023-05-12 at 5 47 35 PM" src="https://github.com/omarcostahamido/musical_non-Markovianity/assets/18335360/7053ed65-082b-49e0-bef5-19d05e45e47b"> -->

## How to run (the new Max version)

- make sure you have [Max/MSP](https://cycling74.com) installed on your machine
- open the [musical_non-Markovianity.maxproj](/musical_non-Markovianity/musical_non-Markovianity.maxproj) file
  - this should launch Max and open the main patch

Note: You can download and run Max for free without authorizing it or activating the 30 day demo. See limitations [here](https://support.cycling74.com/hc/en-us/articles/360049995834-Max-8-Max-7-Authorization#link-2).

### option 1: loading files
- use the `click to open a file` button or drag and drop a file to the area below
  - you can load either `.txt` or `.mid` files
- the top table will auto populate with the contents of the text file or the parsed MIDI file.
- click the button labelled `GO!` to start computing this melody (some intermediary steps will be printed to the console)
- the 5 tables on the right side will display the results

### option 2: live recording
- double click the `midiin` object to select your MIDI input interface
- click the gray square above it - it will light up red, letting you know that it will to record as soon as you start playing
- when done, click the red square again, or press the spacebar, to turn OFF recording
- Bonus tip: in Max, navigate to the menu `Extras > GlobalTransport`. You can change its setting like speed, turn it ON with the button in front of `Activate`, and enable audio click track with the button in front of `Click`

## Reporting problems and getting help
For the Max version:  please check current issues [here](https://github.com/omarcostahamido/musical_non-Markovianity/issues) and add your comment on relevant thread, or open a new issue [here](https://github.com/omarcostahamido/musical_non-Markovianity/issues/new).
For the C version: please check current issues [here](https://github.com/medusamedusa/musical_non-Markovianity/issues) and add your comment on relevant thread, or open a new issue [here](https://github.com/medusamedusa/musical_non-Markovianity/issues/new).
Note: you need a free github account.
