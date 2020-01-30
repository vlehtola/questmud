cmd_last(string str) {
string *channels;
if(!str)
{ write("Usage: last <channel | tell | say | shout | game-info>\n");  return 1; }
str = lower_case(str);

channels = this_player()->query_channel();

if(member_array(str,channels) != -1) {
  command(str+" last");
  return 1;
}
if(str == "tell") {
  command("tell last");
  return 1;
}

if(str == "say") {
  command("say last");
  return 1;
}

if(str == "shout") {
  tail("/log/SHOUT");
  return 1;
}
if(str == "game-info") {
  tail("/log/INFO");
  return 1;
}

write("Usage: last <channel | tell | say | shout | game-info>\n");
return 1;
}
