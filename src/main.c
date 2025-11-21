#include "midi_handling.h" 


int main(int argc, char *argv[])
{
  char *port_name = "hw:2,0,0"; 
  Midi_Data midi_message;

  midi_listen(&midi_message, port_name);
  return 0;
}
