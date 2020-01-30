string message, funktio;
int line, add_line,max_line;
object caller;

/* return 1 if ansi codes are present */

int ansicheck(string s)
{
 string temp;

 if( sscanf(s,"%s"+sprintf("%c",27)+"%s",temp,temp))    return 1;
 if( sscanf(s,sprintf("%c",27)+"%s",temp) )             return 1;
 if( sscanf(s,"%s"+sprintf("%c",27),temp) )             return 1;

 return 0;
}


/*

status ansi_check(string str) {
  string tmp, tmp2, tmp3;
  if(sscanf(str, "%s^[[%s", tmp, tmp2) == 2)
    return 1;
  return 0;
}
 */

start(str,num,ob) {
  line = 0;
  message = allocate(25);
  funktio = str;
  caller = ob;
  if(num) {
    max_line = num;
  } else {
    max_line = 20;
  }
  write("Give message.  Finish message with '**', or '.' to enter command mode\n");
  write("1 ]");
  input_to("more_mail");
  return 1;
}

command_mode() {
  write("Available commands: [Qpads] -- what next?\n");
  input_to("get_command");
  return 1;
}

refresh_array(num) {
  int i,recule;
  while(i<max_line) {
    if(!message[i]) {
      message[i] = message[i+1];
        recule = 1;
    }
    if (recule) { message[i] = message[i+1]; }
    i += 1;
  }
}

get_command(str) {
  int num, i;
  string seko;
  if (!str || str == "") {
    command_mode();
    return 1;
  }
  if (str == "Q") {
    return 1;
  }
  if (str == "p") {
    write("Displaying message:\n");
    while(i<max_line) {
      if(message[i]) { write(message[i]); }
      i += 1;
    }
    command_mode();
    return 1;
  }
  if (str == "s") {
    send_news();
    return 1;
  }
  if (sscanf(str, "a%d", num) == 1) {
    if (num - 1 > line) {
      write("No such line.\n");
      command_mode();
      return 1;
    }
    if (line < max_line) {
      add_line = num - 1;
      refresh_array(num);
      input_to("more_mail");
      return 1;
    }
    write("Cannot add anymore.\n");
    command_mode();
    return 1;
  }
  if (sscanf(str, "d%d", num) == 1) {
    if (num - 1 > line) {
      write("No such line.\n");
      command_mode();
      return 1;
    }
    message[num - 1] = 0;
    write("Line deleted\n");
    refresh_array();
    command_mode();
    return 1;
  }
  command_mode();
  return 1;
}

more_mail(str) {
  if (str == ".") {
    command_mode();
    return 1;
  }
  if (str == "**") {
    send_news();
    return 1;
  }
  if (line > max_line) {
    write("Max "+max_line+" lines.\n");
    command_mode();
    return 1;
  }
  line += 1;
  message[line] = str + "\n";
  write(line + 1 +" ]");
  input_to("more_mail");
  return 1;
}

send_news() {
  int i;
  string msg;
  msg = "";
  while(i < max_line) {
    if (message[i]) { msg = msg + message[i]; }
    i += 1;
  }
  if("/obj/command_d"->ansi_check(msg)) {
    write("Possible ansi code detected.. string cleared.\n");
    msg = "";
  }
  if (!caller) {
     call_other(this_player(), funktio, msg);
  } else {
     call_other(caller, funktio, msg);
  }
  destruct(this_object());
  return 1;
}
