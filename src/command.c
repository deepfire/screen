/* Copyright (C) 2019
 *      Amadeusz Sławiński
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "config.h"

#include "command.h"

#include "screen.h"

#include "misc.h"

/* Command array, should be kept alphabetically sorted */
Command Commands[] = {
	{ "aclchg",		DoCommandAclchg },
	{ "acldel",		DoCommandAcldel },
	{ "aclgrp",		DoCommandAclgrp },
	{ "aclumask",		DoCommandAclumask },
	{ "activity",		DoCommandActivity },
	{ "allpartial",		DoCommandAllpartial },
	{ "altscreen",		DoCommandAltscreen },
	{ "at",			DoCommandAt },
	{ "autodetach",		DoCommandAutodetach },
	{ "autonuke",		DoCommandAutonuke },
	{ "backtick",		DoCommandBacktick },
	{ "bell",		DoCommandBell },
	{ "bind",		DoCommandBind },
	{ "bindkey",		DoCommandBindkey },
	{ "blanker",		DoCommandBlanker },
	{ "blankerprg",		DoCommandBlankerprg },
	{ "break",		DoCommandBreak },
	{ "breaktype",		DoCommandBreaktype },
	{ "bufferfile",		DoCommandBufferfile },
	{ "bumpleft",		DoCommandBumpleft },
	{ "bumpright",		DoCommandBumpright },
	{ "c1",			DoCommandC1 },
	{ "caption",		DoCommandCaption },
	{ "charset",		DoCommandCharset },
	{ "chdir",		DoCommandChdir },
	{ "cjkwidth",		DoCommandCjkwidth },
	{ "clear",		DoCommandClear },
	{ "collapse",		DoCommandCollapse },
	{ "colon",		DoCommandColon },
	{ "command",		DoCommandCommand },
	{ "compacthist",	DoCommandCompacthist },
	{ "console",		DoCommandConsole },
	{ "copy",		DoCommandCopy },
	{ "crlf",		DoCommandCrlf },
	{ "defautonuke",	DoCommandDefautonuke },
	{ "defbce",		DoCommandDefbce },
	{ "defc1",		DoCommandDefc1 },
	{ "defcharset",		DoCommandDefcharset },
	{ "defdynamictitle",	DoCommandDefdynamictitle },
	{ "defencoding",	DoCommandDefencoding },
	{ "defescape",		DoCommandDefescape },
	{ "defflow",		DoCommandDefflow },
	{ "defgr",		DoCommandDefgr },
	{ "defhstatus",		DoCommandDefhstatus },
	{ "deflog",		DoCommandDeflog },
#if defined(ENABLE_UTMP) && defined(LOGOUTOK)
	{ "deflogin",		DoCommandDeflogin },
#endif
	{ "defmode",		DoCommandDefmode },
	{ "defmonitor",		DoCommandDefmonitor },
	{ "defmousetrack",	DoCommandDefmousetrack },
	{ "defnonblock",	DoCommandDefnonblock },
	{ "defobuflimit",	DoCommandDefobuflimit },
	{ "defscrollback",	DoCommandDefscrollback },
	{ "defsilence",		DoCommandDefsilence },
	{ "defslowpaste",	DoCommandDefslowpaste },
	{ "defutf8",		DoCommandDefutf8 },
	{ "defwrap",		DoCommandDefwrap },
	{ "defwritelock",	DoCommandDefwritelock },
	{ "detach",		DoCommandDetach },
	{ "digraph",		DoCommandDigraph },
	{ "dinfo",		DoCommandDinfo },
	{ "displays",		DoCommandDisplays },
	{ "dumptermcap",	DoCommandDumptermcap },
	{ "dynamictitle",	DoCommandDynamictitle },
	{ "echo",		DoCommandEcho },
	{ "encoding",		DoCommandEncoding },
	{ "escape",		DoCommandEscape },
	{ "eval",		DoCommandEval },
	{ "exec",		DoCommandExec },
	{ "fit",		DoCommandFit },
	{ "flow",		DoCommandFlow },
	{ "focus",		DoCommandFocus },
	{ "focusminsize",	DoCommandFocusminsize },
	{ "gr",			DoCommandGr },
	{ "group",		DoCommandGroup },
	{ "hardcopy",		DoCommandHardcopy },
	{ "hardcopy_append",	DoCommandHardcopy_append },
	{ "hardcopydir",	DoCommandHardcopydir },
	{ "hardstatus",		DoCommandHardstatus },
	{ "height",		DoCommandHeight },
	{ "help",		DoCommandHelp },
	{ "history",		DoCommandHistory },
	{ "hstatus",		DoCommandHstatus },
	{ "idle",		DoCommandIdle },
	{ "ignorecase",		DoCommandIgnorecase },
	{ "info",		DoCommandInfo },
	{ "kill",		DoCommandKill },
	{ "lastmsg",		DoCommandLastmsg },
	{ "layout",		DoCommandLayout },
	{ "license",		DoCommandLicense },
	{ "lockscreen",		DoCommandLockscreen },
	{ "log",		DoCommandLog },
	{ "logfile",		DoCommandLogfile },
#if defined(ENABLE_UTMP) && defined(LOGOUTOK)
	{ "login",		DoCommandLogin },
#endif
	{ "logtstamp",		DoCommandLogtstamp },
	{ "mapdefault",		DoCommandMapdefault },
	{ "mapnotnext",		DoCommandMapnotnext },
	{ "maptimeout",		DoCommandMaptimeout },
	{ "markkeys",		DoCommandMarkkeys },
	{ "meta",		DoCommandMeta },
	{ "monitor",		DoCommandMonitor },
	{ "mousetrack",		DoCommandMousetrack },
	{ "msgminwait",		DoCommandMsgminwait },
	{ "msgwait",		DoCommandMsgwait },
	{ "multiinput",		DoCommandMultiinput },
	{ "multiuser",		DoCommandMultiuser },
	{ "next",		DoCommandNext },
	{ "nonblock",		DoCommandNonblock },
	{ "number",		DoCommandNumber },
	{ "obuflimit",		DoCommandObuflimit },
	{ "only",		DoCommandOnly },
	{ "other",		DoCommandOther },
	{ "parent",		DoCommandParent },
	{ "partial",		DoCommandPartial },
	{ "paste",		DoCommandPaste },
	{ "pastefont",		DoCommandPastefont },
	{ "pow_break",		DoCommandPow_break },
	{ "pow_detach",		DoCommandPow_detach },
	{ "pow_detach_msg",	DoCommandPow_detach_msg },
	{ "prev",		DoCommandPrev },
	{ "printcmd",		DoCommandPrintcmd },
	{ "process",		DoCommandProcess },
	{ "quit",		DoCommandQuit },
	{ "readbuf",		DoCommandReadbuf },
	{ "readreg",		DoCommandReadreg },
	{ "redisplay",		DoCommandRedisplay },
	{ "register",		DoCommandRegister },
	{ "remove",		DoCommandRemove },
	{ "removebuf",		DoCommandRemovebuf },
	{ "rendition",		DoCommandRendition },
	{ "reset",		DoCommandReset },
	{ "resize",		DoCommandResize },
	{ "screen",		DoCommandScreen },
	{ "scrollback",		DoCommandScrollback },
	{ "select",		DoCommandSelect },
	{ "sessionname",	DoCommandSessionname },
	{ "setenv",		DoCommandSetenv },
	{ "setsid",		DoCommandSetsid },
	{ "shell",		DoCommandShell },
	{ "shelltitle",		DoCommandShelltitle },
	{ "silence",		DoCommandSilence },
	{ "silencewait",	DoCommandSilencewait },
	{ "sleep",		DoCommandSleep },
	{ "slowpaste",		DoCommandSlowpaste },
	{ "sorendition",	DoCommandSorendition },
	{ "sort",		DoCommandSort },
	{ "source",		DoCommandSource },
	{ "split",		DoCommandSplit },
	{ "startup_message",	DoCommandStartup_message },
	{ "status",		DoCommandStatus },
	{ "stuff",		DoCommandStuff },
	{ "su",			DoCommandSu },
	{ "suspend",		DoCommandSuspend },
	{ "term",		DoCommandTerm },
	{ "terminfo",		DoCommandTerminfo },
	{ "title",		DoCommandTitle },
	{ "truecolor",		DoCommandTruecolor },
	{ "unbindall",		DoCommandUnbindall },
	{ "unsetenv",		DoCommandUnsetenv },
	{ "utf8",		DoCommandUtf8 },
	{ "vbell",		DoCommandVbell },
	{ "vbell_msg",		DoCommandVbell_msg },
	{ "vbellwait",		DoCommandVbellwait },
	{ "verbose",		DoCommandVerbose },
	{ "version",		DoCommandVersion },
	{ "wall",		DoCommandWall },
	{ "width",		DoCommandWidth },
	{ "windowlist",		DoCommandWindowlist },
	{ "windows",		DoCommandWindows },
	{ "wrap",		DoCommandWrap },
	{ "writebuf",		DoCommandWritebuf },
	{ "writelock",		DoCommandWritelock },
	{ "xoff",		DoCommandXoff },
	{ "xon",		DoCommandXon },
	{ "zmodem",		DoCommandZmodem },
	{ "zombie",		DoCommandZombie },
	{ "zombie_timeout",	DoCommandZombie_timeout },
};

int FindCommand(const char *command)
{
	int x, m, l = 0, r = ARRAY_SIZE(Commands);
	while (l <= r) {
		m = (l + r) / 2;
		x = strcmp(command, Commands[m].name);
		if (x > 0)
			l = m + 1;
		else if (x < 0)
			r = m - 1;
		else
			return m;
	}
	return -1;
}


