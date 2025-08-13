#if defined _inc_async_dialogs
	#undef _inc_async_dialogs
#endif 

#if defined async_dialogs_included
	#endinput
#endif
#define async_dialogs_included

#include <PawnPlus>

#if !defined PPD_MAIN_DIALOG_ID
	const PPD_MAIN_DIALOG_ID = 0x502B; // "P+" in ascii hex
#endif

#if !defined PPD_INFO_DIALOG_ID
	const PPD_INFO_DIALOG_ID = 0x502C;
#endif

// NOTE: Since we actually do trolling, it's actually **RECOMMENDED** to place it on top of everything (after a_samp)
// since we don't know which one is still using ShowPlayerDialog

#if defined PPDIALOGS_NO_COMPAT_NATIVE_CALL
	native ShowPlayerDialogStr(playerid, dialogid, DIALOG_STYLE:style, ConstAmxString:caption, ConstAmxString:info, ConstAmxString:button1, ConstAmxString:button2) = ShowPlayerDialog;
#endif

native DialogPlayerShow(playerid, dialogid, DIALOG_STYLE:style, const string:caption[], const string:info[], const string:button1[], const string:button2[]) = ShowPlayerDialog;
#define ShowPlayerDialog DialogPlayerShow

enum e_DIALOG_RESPONSES
{
	Response,
	Listitem,
	InputText[128 + 1],
}

static Task:PlayerDialogTasks[MAX_PLAYERS] = {Task:0, ...};

static CallbackHandler:AsyncDialogResponseHandler;

forward _pp@on_init@PPAsyncDialogs();
public _pp@on_init@PPAsyncDialogs()
{
	// I wish I didn't had to do this, but rewriting the public function header is cool!!1
	wait_ticks(1);

	// Make sure to check if the dialogresponse exists
	if (funcidx("OnDialogResponse") == -1)
	{
		pawn_create_callback("OnDialogResponse", expr_false());
	}

	AsyncDialogResponseHandler = pawn_register_callback("OnDialogResponse", "AsyncDialogsHandler");
}

forward _pp@on_exit@PPAsyncDialogs();
public _pp@on_exit@PPAsyncDialogs()
{
	pawn_unregister_callback(AsyncDialogResponseHandler);
}

stock Task:DialogAsync_ShowPlayer(playerid, DIALOG_STYLE:style, const string:caption[], const string:info[], const string:btnYes[], const string:btnNo[])
{
	#if defined PPDIALOGS_NO_COMPAT_NATIVE_CALL
		ShowPlayerDialog(playerid, PPD_MAIN_DIALOG_ID, style, caption, info, btnYes, btnNo);
	#else
		pawn_call_native("ShowPlayerDialog", "dddssss", playerid, PPD_MAIN_DIALOG_ID, style, caption, info, btnYes, btnNo);
	#endif

	if(PlayerDialogTasks[playerid])
	{
		task_delete(PlayerDialogTasks[playerid]);
	}
	return PlayerDialogTasks[playerid] = task_new();
}

stock Task:DialogAsync_ShowPlayer_s(playerid, DIALOG_STYLE:style, ConstStringTag:caption, ConstStringTag:info, const string:btnYes[], const string:btnNo[])
{
	#if defined PPDIALOGS_NO_COMPAT_NATIVE_CALL
		ShowPlayerDialogStr(playerid, PPD_MAIN_DIALOG_ID, style, caption, info, btnYes, btnNo);
	#else
		pawn_call_native("ShowPlayerDialog", "dddSSss", playerid, PPD_MAIN_DIALOG_ID, style, _:caption, _:info, btnYes, btnNo);
	#endif

	if(PlayerDialogTasks[playerid])
	{
		task_delete(PlayerDialogTasks[playerid]);
	}
	return PlayerDialogTasks[playerid] = task_new();
}

stock Dialog_ShowInfo(playerid, ConstStringTag:caption, ConstStringTag:info, const string:btnYes[], const string:btnNo[])
{
	#if defined PPDIALOGS_NO_COMPAT_NATIVE_CALL
		ShowPlayerDialogStr(playerid, PPD_MAIN_DIALOG_ID, DIALOG_STYLE_MSGBOX, caption, info, btnYes, btnNo);
	#else
		pawn_call_native("ShowPlayerDialog", "dddSSss", playerid, PPD_INFO_DIALOG_ID, DIALOG_STYLE_MSGBOX, _:caption, _:info, btnYes, btnNo);
	#endif
	return 1;
}

forward AsyncDialogsHandler(playerid, dialogid, response, listitem, const string:inputtext[]);
public AsyncDialogsHandler(playerid, dialogid, response, listitem, const string:inputtext[])
{
	if(dialogid == PPD_MAIN_DIALOG_ID)
	{
		new dialog_response[e_DIALOG_RESPONSES];
		dialog_response[Response] = response;
		dialog_response[Listitem] = listitem;
		strcat(dialog_response[InputText], inputtext, 129);

		new const Task:task = PlayerDialogTasks[playerid];
		PlayerDialogTasks[playerid] = Task:0;
		task_set_result_arr(task, dialog_response);

		return 1;
	}
	return 0;
}