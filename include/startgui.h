 /* BonkEnc Audio Encoder
  * Copyright (C) 2001-2011 Robert Kausch <robert.kausch@bonkenc.org>
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the "GNU General Public License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef H_BONKENC_MAIN
#define H_BONKENC_MAIN

#include <smooth.h>
#include "bonkenc.h"

#include <gui/main_joblist.h>
#include <gui/main_threads.h>

#ifdef __WIN32__
#	define DLLEXPORT __declspec(dllexport)
#else
#	define DLLEXPORT
#endif

using namespace smooth;
using namespace smooth::GUI;

using namespace BoCA::AS;

extern "C"
{
	Int DLLEXPORT StartGUI(const Array<String> &);
}

namespace BonkEnc
{
	class BonkEncGUI : public BonkEnc
	{
		private:
			/* Singleton class, therefore protected constructor/destructor
			 */
							 BonkEncGUI();
							~BonkEncGUI();

			PopupMenu			*menu_file;
			PopupMenu			*menu_addsubmenu;
			PopupMenu			*menu_files;
			PopupMenu			*menu_drives;

			PopupMenu			*menu_database;
			PopupMenu			*menu_database_query;

			PopupMenu			*menu_options;
			PopupMenu			*menu_configurations;
			PopupMenu			*menu_seldrive;

			PopupMenu			*menu_encode;
			PopupMenu			*menu_encoders;
			PopupMenu			*menu_encoder_options;

			PopupMenu			*menu_help;

			MenuEntry			*allowOverwriteMenuEntry;

			Menubar				*mainWnd_menubar;
			Menubar				*mainWnd_iconbar;
			Titlebar			*mainWnd_titlebar;

			TabWidget			*tabs_main;
			LayerJoblist			*tab_layer_joblist;
			LayerThreads			*tab_layer_threads;

			Int				 clicked_configuration;
			Int				 clicked_drive;
			Int				 clicked_encoder;

			Array<ExtensionComponent *>	 extensionComponents;

			Void				 InitExtensionComponents();
			Void				 FreeExtensionComponents();

			Void				 Close();
			Void				 About();

			Void				 ConfigureEncoder();
			Void				 ConfigureSettings();

			Void				 ReadSpecificCD();

			Void				 EncodeSpecific();
			Void				 ShowHelp();
			Void				 ShowTipOfTheDay();

			Void				 CheckForUpdates();

			Bool				 SetLanguage();
			Void				 FillMenus();

			Void				 Encode();

			Void				 PauseResumeEncoding();
			Void				 StopEncoding();
		slots:
			Bool				 ExitProc();

			Void				 MessageProc(Int, Int, Int);

			Void				 OnChangePosition(const Point &);
			Void				 OnChangeSize(const Size &);

			Void				 OnSelectConfiguration();

			Void				 ReadCD();

			Void				 QueryCDDB();
			Void				 QueryCDDBLater();
			Void				 SubmitCDDBData();

			Void				 ManageCDDBData();
			Void				 ManageCDDBBatchData();
			Void				 ManageCDDBBatchQueries();

			Void				 AddFilesFromDirectory();
			Void				 AddFilesByPattern();

			Void				 ToggleUseInputDirectory();
			Void				 ToggleEncodeToSingleFile();

			Void				 ConfirmDeleteAfterEncoding();
		public:
			/* Returns a new or existing instance of BonkEncGUI
			 */
			static BonkEncGUI		*Get();

			/* Destroys an existing instance of BonkEncGUI
			 */
			static Void			 Free();
	};
};

#endif