string x;
set_x_value()
{
x = "m";
save_object("/wizards/luminarc/test1.o");
return 1;
}
reset_x_value()
{
x = "0";
return 1;
}
load_x_value()
{
return 1;
}
show_x_value()
{
write(x);
return 1;
}

