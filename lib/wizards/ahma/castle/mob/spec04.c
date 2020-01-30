inherit "obj/monster";

id(str) { return str == "spec"; }

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(!chat_str) {
    chat_str = allocate(8);
    chat_str[0] = "A voice in your head: 'What is the value of life?'\n";
    chat_str[1] = "A voice in your head: 'You can discover new things about you if you jump.'\n";
    chat_str[2] = "A voice in your head: 'Can you see the truth?'\n";
    chat_str[3] = "A voice in your head: 'The life is worthless without new experiences.'\n";
    chat_str[4] = "A voice in your head: 'Death is the plane of victory.'\n";
    chat_str[5] = "A voice in your head: 'The meaning of life? No, life has no meaning.'\n";
    chat_str[6] = "A voice in your head: 'Who wants to stop you? You have no one so dear.'\n";
    chat_str[7] = "A voice in your head: 'The gates are open, open for you.'\n";
  }
  load_chat(20, chat_str);
}
    







