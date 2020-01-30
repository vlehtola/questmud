/* buffer for log msgs to be displayed at log chan //Celtron */
#define CHANNEL_D	"/daemons/channel_d"

static mapping messages;
static int e;

void reset(mixed arg) {
  if(arg) return;
  messages = ([ ]);
}

query_messages() {
  return messages;
}

add_buffer(string msg) {
  e += 1;
  messages += ([ e : msg ]);
  call_out("send_to_chan", 2, msg);
}

send_to_chan(string msg) {
  CHANNEL_D->print_log(msg);
}
