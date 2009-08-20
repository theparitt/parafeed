/*
 * Copyright (c) 2000-2008, 2009 S.Bhatnagar
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#ifdef __cpluscplus
extern "C" {
#endif

char*  dupstr (char *s);
char*  rl_command_generator(const char *text,int state);
char** command_completor(const char *text, int start, int end);
void   initialize_readline();
void   mkfilename(char *out,char *envvar,char *name,char *type);
void   save_hist(char *EnvVar, char *Default);
void   limit_hist(char *EnvVar, int Default);
void   load_hist(char *EnvVar, char *Default);

#ifdef __cpluscplus
}
#endif
