/* This file lists the books of spells in each section  //Celtron */
/* ..also displays the spell helps and checks if the player is allowed to read the book */

#define DIR    "/guilds/spell_descs/"
#define RANK_D "/daemons/guildrank_d"

mapping book_list;
static string searching;

reset(arg) {
  if(arg) return;
  book_list = ([ ]);
}

string section_name() {
  string tmp;
  if(sscanf(file_name(this_object()), "/guilds/library/%s_section", tmp) == 1)
    return tmp;
  return 0;
}

mixed random_arr(mixed *array) {
  mixed *arraymix;
  int i, e;

  arraymix = allocate(sizeof(array));
  i = random(sizeof(arraymix));
  while(e < sizeof(array)) {
    while(arraymix[i]) i = random(sizeof(arraymix));
    arraymix[i] = array[e];
    e++;
  }
  return arraymix;
}

void book_list(object player) {
  int rank, max_rank, books, i;
  string guild_name, *file_arr, files, tmp1, tmp2, *list, SECTION;
  searching = 0;
  if(!player) player = this_player();
  SECTION = section_name();
  if(SECTION == "essence") guild_name = "mage";
  if(SECTION == "channel") guild_name = "cleric";
  if(SECTION == "abjuration") guild_name = "abjurer";
  if(SECTION == "necromancy") guild_name = "necromancer";
  if(SECTION == "chaos") guild_name = "warlock";
  if(!guild_name) {
    tell_object(player, "No such section.\n");
    return;
  }

  rank = RANK_D->count_rank_score(player, guild_name);
  max_rank = RANK_D->count_rank_score(0, guild_name, 1);

  books = rank*10/max_rank;
  if(!books) {
    tell_object(player, "You don't have enough knowledge in "+SECTION+" to know where to start.\n");
    return;
  }
  files = "";
  file_arr = get_dir(DIR+SECTION+"/");
  file_arr = random_arr(file_arr);
  list = allocate(books);
  for(i=0 ; i < sizeof(file_arr) && i < books ; i++) {
    if(sscanf(file_arr[i], "%s_%s", tmp1, tmp2) == 2)
	list[i] = tmp1 + " " + tmp2;
    else
      list[i] = file_arr[i];
    files += list[i]+" \n";
  }
  tell_object(player, "The following books catch your attention:\n"+files);
  book_list -= ([ player ]);
  book_list += ([ player : list ]);
}

void read_book(string book, object player) {
  int i;
  string tmp;
  if(!player) player = this_player();
  if(!book || !book_list[player]) {
    tell_object(player, "You can't find such a book.\n");
    return;
  }
  for(i=0 ; i < sizeof(book_list[player]) ; i++) {
    if(book_list[player][i] == book) {
      if(sscanf(book, "%s %s", book, tmp) == 2)
	book += "_"+tmp;
      cat(DIR+section_name()+"/"+book);
      return;
    }
  }
  tell_object(player, "You have no clue of the book's location or if it even exists.\n");
}

library_init() {
  add_action("pre_read_book", "read");
  add_action("search_book", "search");
}

status pre_read_book(string str) {
  if(!str) {
    write("Read what book?\n");
    return 1;
  }
  read_book(str, this_player());
  return 1;
}

status search_book(string str) {
  object ob;
  if(searching) ob = find_player(searching);
  if(ob && !present(ob, this_object() )) searching = 0;
  if(searching) {
    if(searching == this_player()->query_name())
      write("You are already searching.\n");
    else
      write("You cannot search while "+searching+" is searching for books.\n");
    return 1;
  }
  write("You start searching for intresting books..\n");
  searching = this_player()->query_name();
  call_out("book_list", 4, this_player());
  return 1;
}


