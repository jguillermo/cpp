VERSION 5.00
Begin VB.Form principal 
   Caption         =   "Form1"
   ClientHeight    =   7665
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   12390
   LinkTopic       =   "Form1"
   ScaleHeight     =   7665
   ScaleWidth      =   12390
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton CMDelimina 
      Caption         =   "ELIMINA"
      Height          =   735
      Left            =   9720
      TabIndex        =   5
      Top             =   3720
      Width           =   2175
   End
   Begin VB.CommandButton CMDmodifica 
      Caption         =   "MODIFICA"
      Height          =   735
      Left            =   7320
      TabIndex        =   4
      Top             =   3720
      Width           =   2055
   End
   Begin VB.CommandButton CMDlista 
      Caption         =   "LISTA"
      Height          =   735
      Left            =   5160
      TabIndex        =   3
      Top             =   3720
      Width           =   1935
   End
   Begin VB.CommandButton CMDbusca 
      Caption         =   "BUSCA"
      Height          =   735
      Left            =   3120
      TabIndex        =   2
      Top             =   3720
      Width           =   1815
   End
   Begin VB.CommandButton CMDcrear 
      Caption         =   "CREAR ITEM"
      Height          =   735
      Left            =   1080
      TabIndex        =   1
      Top             =   3720
      Width           =   1815
   End
   Begin VB.Label Label1 
      Caption         =   "TIENDA GUILLE"
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   48
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   1455
      Left            =   1920
      TabIndex        =   0
      Top             =   1560
      Width           =   8055
   End
End
Attribute VB_Name = "principal"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub CMDbusca_Click()
busca.Show

End Sub

Private Sub CMDcrear_Click()
crearItem.Show
End Sub

Private Sub CMDelimina_Click()
elimina.Show

End Sub

Private Sub CMDlista_Click()
lista.Show

End Sub

Private Sub CMDmodifica_Click()
modifica.Show

End Sub
