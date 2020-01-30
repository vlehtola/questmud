reset(arg) {
  if(arg) return;
}

short() {
  return "A pile of gray bones";
}

id(str) {
  return str == "bones";
}

long() {
  write("A pile of bit grayish bones. All the flesh has been, probably, eaten away\n" +
        "from the bones, making them to look almost shiny. Seems that these bones\n" +
        "could even be used as a firewood.\n");
}

get() {
  return 1;
}

query_weight() {
  return 30;
}
