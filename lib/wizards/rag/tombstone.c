mapping people;

init() {
  add_action("light","candle");
}

reset(arg) {
  if(arg) return;
  people = ([]);
}

short() { return "A lonely tombstone"; }

id(str) { return str == "tombstone" || str == "stone"; }

long() {
  string *names;
  int i,j;
  write("This tombstone is carved from the finest ivory.\n"+
        "It stands here to honor the memory of Crusher\n"+
        "who passed away today. It is covered with images\n"+
        "depicting his epic journeys in the world of Deleria.\n"+
        "              Rest in peace!\n\n"+
        "The following people have lighted a candle in his memory:\n");
  names = m_indices(people);
  j = 0;
  for(i = 0; i < sizeof(names); i++) {
    write(names[i]);
    if( i != sizeof(names) - 1 ) {
      write(", ");
    }
    j++;
    if ( j == 6 ) {
      write("\n");
      j = 0;
    }
  }
  write("\nTo light a candle, type 'candle'\n");
  return 1;
}

get() { return 0; }

query_weight() { return 500; }

light() {
  if ( people[this_player()->query_name()] ) { return 1; }
  
  people += ([ (string)this_player()->query_name(): (int)1 ]);
  write("You light a candle in Crusher's memory.\n");
  say(this_player()->query_name()+" lights a candle.\n");
  return 1;
}

add_name(str) {
  people += ([ (string)str: (int)1 ]);
  return 1;
}