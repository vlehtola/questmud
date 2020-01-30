cmd_psay(string arg) {
#define channel_d "/daemons/channel_d.c"
,
 string array args = ({});
 string party,message;
 if(!arg || arg=="") {
  write("Usage: psay <party> <message>\n");
  return 1;
 }
 args = explode(arg," ");
 party = args[0];
 if(sizeof(args) < 2) {
  write("Usage: psay <party> <message>\n");
  return 1;
 }
 message = arg[strlen(party)+1..];
 write("Delivered to ["+party+"]: "+message+"\n");
 channel_d->deliver_party(party, this_player(), message);
 return 1;
}
