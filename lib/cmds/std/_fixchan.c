cmd_fixchan(string arg) {
  write("Attempting to leave 'channels' channel.. "+this_player()->remove_channel("channels")+"\n");
  return 1;
}
