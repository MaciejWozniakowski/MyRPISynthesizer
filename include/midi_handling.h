#include <stdint.h>

typedef struct {
  unsigned char status;  
  unsigned char data1;  
  unsigned char data2;  
} Midi_Data;

void midi_listen(Midi_Data * midi_message, char * port_name);
void process_midi_message(Midi_Data * midi_message);
