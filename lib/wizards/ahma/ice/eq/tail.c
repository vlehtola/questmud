reset(arg) {
  if(arg) return;
}

short() {
  return "Trunz's tail";
}

id(str) {
  return str == "tail";
}

long() {
  write("This tail formerly belonged to Harald's pet wolverine, Trunz.\n" +
        "Somehow the tail seems to be more furrier than other wolverines'\n" +
        "tails you have seen. Dried blood and some severed blood vessels\n" +
        "can be seen in the tip of the tail which before was attached to\n" +
        "the poor animal's body.\n");
}

get() {
  return 1;
}

query_weight() {
  return 10;
}
