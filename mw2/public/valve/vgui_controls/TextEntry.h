//========= Copyright � 1996-2003, Valve LLC, All rights reserved. ============
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// Purpose: A Class to create a window that you can type and edit text in.
//          Window can hold single line or multiline text. 
//          If it is single it can scroll horizontally in response to 
//          key input and mouse selection.
//
// $NoKeywords: $
//=============================================================================

#ifndef TEXTENTRY_H
#define TEXTENTRY_H

#ifdef _WIN32
#pragma once
#endif

#include <vgui/VGUI.h>
#include <Color.h>
#include <vgui_controls/Panel.h>
#include <vgui_controls/Label.h>

#include <UtlVector.h>

namespace vgui
{

class ClickPanel;

//-----------------------------------------------------------------------------
// Purpose: Text-input handler
// Behaviour Specs:
//	This class handles input from mouse and keyboard.
//  TextEntry classes support several box styles, horizontal scrolling with no scrollbar
//  vertical scrolling with or without a scrollbar, single line, multiline,
//  editable and noneditable.
//
// Shared behaviour:
//  URL's are a different text color and are clickable. Clicking them brings up a web browser.
//  For vertical scroll bars, up and down arrows scroll one line at a time.
//  Clicking and dragging the nob scrolls through text lines.
//  Mouse wheel also moves the nob.
//  User can select and highlight text in the window. 
//  Double clicking on a word selects it.
//
// Non editable:
//	No blinking cursor in non editable windows.
//  Right clicking mouse opens copy menu. Menu's top left corner is where mouse is.
//  Ctrl-c will also copy the text.
// Editable:
//	Blinking cursor is positioned where text will be inserted.
//  Text keys type chars in the window.
//  ctrl-c copy highlighted text
//  ctrl-v paste highlighted text
//  ctrl-x cut highlighted text
//  ctrl-right arrow move cursor to the start of the next word
//  ctrl-left arrow move cursor to the start of the prev word
//  ctrl-enter delete the selected text (and inserts a newline if _catchEnterKey is true)
//  insert delete selected text and pastes text from the clipboard
//  delete delete the selected text
//  ctrl-home move cursor to the start of the text
//  ctrl-end move cursor to the end of the text.
//  left arrow move cursor before prev char
//  ctrl-shift left/right arrow selects text a word at a time
//  right arrow move cursor before next char
//  up arrow move cursor up one line.
//  down arrow move cursor down one line. 
//  home move cursor to start of current line
//  end move cursor to end of current line
//  backspace delete prev char or selected text.
//  Trying to move to the prev/next char/line/word when there is none moves the cursor to the
//  start/end of the text.
// Horizontal scrolling:
//  Trying to move to the prev/next char/line/word when there is none scrolls the text
//  horizontally in the window so the new text displays at the correct side.
//  When moving to prev chars scrolling is staggered. To next chars it is one char at a time.
// Cut/Copy/Paste Menu:
//  Right clicking mouse brings up cut/copy/paste menu.
//  If no text is highlighted the cut/copy options are dimmed. Cut is dimmed in non editable panels
//  If there is no text in the clipboard or panel is not editable the paste option is dimmed.
//  If the mouse is right clicked over selected text, the text stays selected.
//  If the mouse is right clicked over unselected text, any selected text is deselected.
//  
//	
//-----------------------------------------------------------------------------
class TextEntry : public Panel
{
public:
	TextEntry(Panel *parent, const char *panelName);
	virtual ~TextEntry();

	virtual void SetText(const wchar_t *wszText);
	virtual void SetText(const char *text);
	virtual void GetText(char *buf, int bufLen);
	virtual void GetText(wchar_t *buf, int bufLen);

	// editing
	virtual void GotoLeft();		// move cursor one char left
	virtual void GotoRight();		// move cursor one char right
	virtual void GotoUp();			// move cursor one line up
	virtual void GotoDown();		// move cursor one line down
	virtual void GotoWordRight();	// move cursor to Start of next word
	virtual void GotoWordLeft();	// move cursor to Start of prev word
	virtual void GotoFirstOfLine();	// go to Start of the current line 
	virtual void GotoEndOfLine();	// go to end of the current line 
	virtual void GotoTextStart();	// go to Start of text buffer
	virtual void GotoTextEnd();		// go to end of text buffer

	virtual void InsertChar(wchar_t ch);
	virtual void InsertString(const char *text);
	virtual void InsertString(wchar_t *wszText);
	virtual void Backspace();								   
	virtual void Delete();
	virtual void SelectNone();
	virtual void OpenEditMenu();
	virtual void CutSelected();
	virtual void CopySelected();
	virtual void Paste();
	virtual void DeleteSelected();
	virtual void Undo();
	virtual void SaveUndoState();
	virtual void SetFont(HFont font);
	virtual void SetTextHidden(bool bHideText);
	virtual void SetEditable(bool state);
	virtual bool IsEditable();
	virtual void SetEnabled(bool state);
	// move the cursor to line 'line', given how many pixels are in a line
	virtual void MoveCursor(int line, int pixelsAcross);	

	// sets the color of the background when the control is disabled
	virtual void SetDisabledBgColor(Color col);
	
	// set whether the box handles more than one line of entry
	virtual void SetMultiline(bool state);

	// sets visibility of scrollbar
	virtual void SetVerticalScrollbar(bool state);

	// sets whether or not the edit catches and stores ENTER key presses
	virtual void SetCatchEnterKey(bool state);

	// sets whether or not to send "TextNewLine" msgs when ENTER key is pressed
	virtual void SendNewLine(bool send);

	// sets limit of number of characters insertable into field; set to -1 to remove maximum
	// only works with if rich-edit is NOT enabled
	virtual void SetMaximumCharCount(int maxChars);
	virtual int GetMaximumCharCount();

	// sets whether to wrap text once maxChars is reached (on a line by line basis)
	virtual void SetWrap(bool wrap);

	virtual void RecalculateLineBreaks();
	virtual void LayoutVerticalScrollBarSlider();

	virtual bool RequestInfo(KeyValues *outputData);

	// sets the height of the window so all text is visible.
	// used by tooltips
	void SetToFullHeight();

	// sets the width of the window so all text is visible. (will create one line)
	// used by tooltips
	void SetToFullWidth();

	int GetNumLines();

	/* INFO HANDLING
		"GetText"
			returns:
				"text" - text contained in the text box
	*/

	DECLARE_PANELMAP();
	/* CUSTOM MESSAGE HANDLING
		"SetText"
			input:	"text"	- text is set to be this string
	*/

	/* MESSAGE SENDING (to action signal targets)
		"TextChanged"	- sent when the text is edited by the user
			
		"TextNewLine" - sent when the end key is pressed in the text entry AND _sendNewLines is true
	*/

	// Selects all the text in the text entry.
	void SelectAllText(bool bResetCursorPos);
	void SelectNoText();
	void SelectAllOnFirstFocus( bool status );
	void SetDrawWidth(int width); // width from right side of window we have to draw in
	int GetDrawWidth();
	void SetHorizontalScrolling(bool status); // turn horizontal scrolling on or off.

	// sets whether or not number input only is allowed
	void SetAllowNumericInputOnly(bool state);

protected:
	virtual void ResetCursorBlink();
	virtual void PerformLayout();  // layout the text in the window
	virtual void ApplySchemeSettings(IScheme *pScheme);
	virtual void PaintBackground();
	virtual int  DrawChar(wchar_t ch, HFont font, int index, int x, int y);
	virtual bool DrawCursor(int x, int y);

	virtual void SetCharAt(wchar_t ch, int index); // set the value of a char in the text buffer
	virtual void ApplySettings( KeyValues *inResourceData );
	virtual void GetSettings( KeyValues *outResourceData );
	virtual const char *GetDescription( void );
	virtual void FireActionSignal();
	virtual bool GetSelectedRange(int& cx0,int& cx1);
	virtual void CursorToPixelSpace(int cursorPos, int &cx, int &cy);
	virtual int  PixelToCursorSpace(int cx, int cy);
	virtual void AddAnotherLine(int &cx, int &cy);
	virtual int  GetYStart(); // works out ypixel position drawing started at

	virtual void SelectCheck();	 // check if we are in text selection mode
	virtual void OnSetText(const wchar_t *text);
	virtual void OnSliderMoved(); // respond to scroll bar events
	virtual void OnKillFocus();
	virtual void OnMouseWheeled(int delta);	// respond to mouse wheel events
	virtual void OnKeyCodeTyped(KeyCode code);	//respond to keyboard events
	virtual	void OnKeyTyped(wchar_t unichar);	//respond to keyboard events

	virtual void OnCursorMoved(int x, int y);  // respond to moving the cursor with mouse button down
	virtual void OnMousePressed(MouseCode code); // respond to mouse down events
	virtual void OnMouseDoublePressed(MouseCode code);
	virtual void OnMouseReleased(MouseCode codel);	// respond to mouse up events

	virtual void OnKeyFocusTicked(); // do while window has keyboard focus
	virtual void OnMouseFocusTicked(); // do while window has mouse focus
	virtual void OnCursorEntered();	 // handle cursor entering window
	virtual void OnCursorExited();	 // handle cursor exiting window

	virtual void OnMouseCaptureLost(); 
	virtual void OnSizeChanged(int newWide, int newTall);

	// Returns the character index the drawing should Start at
	virtual int GetStartDrawIndex(int &lineBreakIndexIndex);
	
    void ScrollRight(); // scroll to right until cursor is visible
    void ScrollLeft();  // scroll to left 
	bool IsCursorOffRightSideOfWindow(int cursorPos); // check if cursor is off right side of window
	bool IsCursorOffLeftSideOfWindow(int cursorPos); // check if cursor is off left side of window
    void ScrollLeftForResize();
	
	void OnSetFocus();

private:
	void OnSetState(int state);
	// get index in buffer of the Start of the current line we are on
	int GetCurrentLineStart();
	// get index in buffer of the end of the current line we are on
	int GetCurrentLineEnd();
	bool IsLineBreak(int index);
	int GetCursorLine();
	void MoveScrollBar(int delta);
	void CalcBreakIndex(); // calculate _recalculateLineBreaksIndex
	void CreateEditMenu(); // create copy/cut/paste menu

private:
	CUtlVector<wchar_t> m_TextStream;		// the text in the text window is stored in this buffer
	CUtlVector<wchar_t> m_UndoTextStream;	// a copy of the text buffer to revert changes
	CUtlVector<int>		m_LineBreaks;		// an array that holds the index in the buffer to wrap lines at

	int                _cursorPos;		// the position in the text buffer of the blinking cursor
	bool               _cursorIsAtEnd;
	bool               _putCursorAtEnd;
	int				   _undoCursorPos;	// a copy of the cursor position to revert changes
	bool               _cursorBlink;	// whether cursor is blinking or not
	bool               _hideText;		// whether text is visible on screen or not
	bool			   _editable;		// whether text is editable or not
	bool			   _mouseSelection;	// whether we are highlighting text or not (selecting text)
	bool			   _mouseDragSelection; // tells weather mouse is outside window and button is down so we select text
	int				   _mouseSelectCursorStart;	// where mouse button was pressed down in text window
	long               _cursorNextBlinkTime;  // time of next cursor blink
	int                _cursorBlinkRate;	  // speed of cursor blinking
	int                _select[2];	// select[1] is the offset in the text to where the cursor is currently
									// select[0] is the offset to where the cursor was dragged to. or -1 if no drag.
	int				   _pixelsIndent;
	int				   _charCount;
	int				   _maxCharCount;  // max number of chars that can be in the text buffer
	HFont              _font;		   // font of chars in the text buffer
	bool			   _dataChanged;   // whether anything in the window has changed.
	bool			   _multiline;	   // whether buffer is multiline or just a single line
	bool			   _verticalScrollbar; // whether window has a vertical scroll bar
	ScrollBar		  *_vertScrollBar;		  // the scroll bar used in the window
	Color			   _cursorColor;	  // color of the text cursor
	Color			   _disabledFgColor;
	Color			   _disabledBgColor;
	Color			   _selectionColor;
	Color			   _selectionTextColor;	 // color of the highlighted text
	Color			   _defaultSelectionBG2Color;
	int				   _currentStartLine; // use for checking vertical text scrolling (multiline)
	int				   _currentStartIndex; // use for horizontal text scrolling (!multiline)
	bool			   _horizScrollingAllowed;	// use to disable horizontal text scrolling period.
	Color			   _focusEdgeColor;
	bool		       _catchEnterKey;
	bool			   _wrap;
	bool			   _sendNewLines;
	int				   _drawWidth;
	int					_scrollBarSize;

	// selection data
	Menu				*m_pEditMenu; ///cut/copy/paste popup

	int				   _recalculateBreaksIndex; // tells next linebreakindex index to Start recalculating line breaks	
	bool			   _selectAllOnFirstFocus; // highlights all text in window when focus is gained.
	bool			   _firstFocusStatus; // keep track if we've had that first focus or not
	bool				m_bAllowNumericInputOnly;

	typedef Panel BaseClass;
};

}

#endif // TEXTENTRY_H
