get_short(num) { return "Inside a house ("+num+")"; }

get_long(num) {
  string str;
  str = "";
  if (num < 9) str =
"You are inside a small house. There is a bed and a small table in the\n"+
"corner of this only room. There is also a drawer where you can\n"+
"store your eq.\n";
  str +=
"Available commands are:\n" +
"     list\n" +
"     store [item] to [slot]\n" +
"     withdraw [slot]\n";
  return str;
}

get_fireplace_heal() {
  return 10;
}
