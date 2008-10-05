/* File:      flrprint.H
**
** Author(s): Guizhen Yang
**
** Contact:   kifer@cs.stonybrook.edu
**
** Copyright (C) by
**      The Research Foundation of the State University of New York, 1999-2008.
**
** All rights reserved.
**
** For information about licensing terms, please see
** http://silk.projects.semwebcentral.org/flora2-license.html
**
**
*/



:- import format/2, format/3 from format.


:- export
	flora_current_out_nl/0,
	flora_current_out_string/1,
	flora_current_out_string/2,
	flora_current_out_line/1,
	flora_current_out_line/2,

	flora_stream_out_nl/1,
	flora_stream_out_string/2,
	flora_stream_out_string/3,
	flora_stream_out_line/2,
	flora_stream_out_line/3,

	flora_stderr_nl/0,
	flora_stderr_string/1,
	flora_stderr_string/2,

	flora_stdwarn_nl/0,
	flora_stdwarn_string/1,
	flora_stdwarn_string/2,
	
	flora_stdmsg_nl/0,
	flora_stdmsg_string/1,
	flora_stdmsg_string/2,
	flora_stdmsg_line/1,
	
	flora_stdfdbk_nl/0,
	flora_stdfdbk_string/1,
	flora_stdfdbk_string/2,
	flora_stdfdbk_line/1,
	
	flora_error_heading/0,
	flora_error_indentline/0,
	flora_warning_heading/0,
	flora_warning_indentline/0,
	flora_message_heading/0,
	flora_message_tailing/0,
	
	flora_error_line/1,
	flora_error_line/2,
	
	flora_warning_line/1,
	flora_warning_line/2,
	
	flora_message_line/1,
	flora_message_line/2,
	
	flora_err_stream/1,
	flora_warn_stream/1,
	flora_msg_stream/1,
	flora_fdbk_stream/1.
