#include <stdio.h>
#include <stdlib.h>
#include <alsa/asoundlib.h>
#include <inttypes.h>

#include "midi_handling.h"

/*
 *Keep it simple at first!!!
 * 1 connect the keyboard to RPI - hardcode the port name 
 * 2 make an int frequency the returned valuue of midi_listen()
 *
 *
 * bin*/

void process_midi_message(Midi_Data * midi_message){
  uint8_t satus_bin; 
  uint8_t data1_bin; 
  uint8_t data2_bin;
  //zamien midi_message na czestotliwosc oraz czy nuta gra czy nie 
  //odpal adekwatny 
}

void midi_listen(Midi_Data * midi_message, char * port_name){
    snd_rawmidi_t *midi_in = NULL;

    if (snd_rawmidi_open(&midi_in, NULL, port_name, SND_RAWMIDI_NONBLOCK) < 0) {
        fprintf(stderr, "Error: Cannot open MIDI input port %s\n", port_name);
    }

    printf("Listening for MIDI messages on %s...\n", port_name);

    while (1) { 
        ssize_t ret;
        ret  = snd_rawmidi_read(midi_in, midi_message, sizeof(*midi_message));
        if(ret > 0){
          printf("Received bytes: %02X %02X %02X\n",  midi_message->status,
          midi_message->data1, 
          midi_message->data2);
          process_midi_message(midi_message);
          usleep(100); 
        }
    }
    snd_rawmidi_close(midi_in);
}


