// Heavy modification by Celtron 09.04.2004

#define SPELL_FUN "/guilds/obj/spellfun"
#define SCROLL_D "/guilds/mage/objects/scroll_daemon"

string _name, _short, _long, _label, _word1, _word2, _word3, owner;
status _can_read;

reset(arg) {
    if (arg)
        return;
   _short = "A empty scroll";
   _name = "scroll";
}

string query_name() { return _name; }
string short() { if(_label) { return _short+" named as '"+_label+"'"; } return _short; }
string query_word1() { return _word1; }
string query_word2() { return _word2; }
string query_word3() { return _word3; }
query_scroll() { return this_object(); }
query_can_label() { return 1; }
set_label(string w) { _label=w; }
set_owner(string w) { owner=w; }
query_owner() { return owner; }

query_read() { return _can_read; }
void create() {
}
id(str) { return str == _name || str == _label; }

get() { return 1; }

drop() { return 0; }

status add_new_syllabe(string str) {
  string skill, msg;
  if(!str) {
    tell_object(this_player(), "Failed.\n");
    return 1;
  }
  skill = SPELL_FUN->get_skill_num(lower_case(str));
  if(!skill) { tell_object(this_player(), "No such word.\n"); return 1; }

  if(this_player()->query_skills(skill) < random(100)) {
    tell_object(this_player(), "You accidentally make a mistake spelling the syllabe and the scroll is ruined.\n");
    say(this_player()->query_name()+" fails to scribble something on the scroll.\n");
    SCROLL_D->reduce_maker(this_player()->query_name());
    destruct(this_object());
    return 1;
  }
  tell_object(this_player(), "You scribble the syllabe '"+str+"' on the scroll.\n");
  say(this_player()->query_name()+" scribbles something on the scroll.\n");

  if(!_word1) {
    _word1 = str;
    msg = _word1;
    _short = "A scroll with something scribbled on it";
  } else if(!_word2) {
    msg = _word1 + " " + _word2;
    _word2 = str; 
  } else if(!_word3) {
    _word3 = str;
    msg = _word1 + " " + _word2 + " " + _word3;
    _can_read = 1;
  } else {
    write("The scroll already contains three syllabes.\n");
    return 1;
  }
  write("The scroll now reads '"+msg+"'.\n");
  return 1;
}

query_long() { return _long; }

query_weight() { return 10; }

long() {
        _long = "";
        _long += "A magical scroll.\n";
        if(!_word1)_long += "The scroll is empty.";
        if(_word1)_long += "The scroll has something scribbled on: "+_word1;
        if(_word2)_long += ", "+_word2;
        if(_word3)_long += " and "+_word3;
        _long += "\n";
        _long += "This scroll was created by "+owner+".\n";
        write(_long);
        return 1;
}
