reset(arg) {
  if(arg) return;
}

short() {
  return "Few stalks of a yellowish weed";
}

id(str) {
  return str == "weed";
}

long() {
  write("You are not quite sure what these weeds are, but it seems that they are\n" +
        "mostly coloured in yellow. The bunch of weeds emit quite strong scent\n" +
        "which you cannot recognize for certain. Seems that these weeds could be\n" +
        "smoked with an appropriate pipe.\n");
}

get() {
  return 1;
}

query_weight() {
  return 1;
}
