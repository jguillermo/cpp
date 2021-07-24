VERSION 5.00
Object = "{0ECD9B60-23AA-11D0-B351-00A0C9055D8E}#6.0#0"; "MSHFLXGD.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7620
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   12315
   LinkTopic       =   "Form1"
   ScaleHeight     =   7620
   ScaleWidth      =   12315
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   ">>"
      Height          =   375
      Left            =   8760
      TabIndex        =   12
      Top             =   1080
      Width           =   735
   End
   Begin VB.CommandButton Command3 
      Caption         =   ">"
      Height          =   375
      Left            =   8040
      TabIndex        =   11
      Top             =   1080
      Width           =   735
   End
   Begin VB.CommandButton Command2 
      Caption         =   "<"
      Height          =   375
      Left            =   7440
      TabIndex        =   10
      Top             =   1080
      Width           =   615
   End
   Begin VB.CommandButton Command1 
      Caption         =   "<<"
      Height          =   375
      Left            =   6840
      TabIndex        =   9
      Top             =   1080
      Width           =   615
   End
   Begin VB.TextBox txtunidad 
      DataField       =   "unidad"
      DataMember      =   "producto"
      DataSource      =   "d"
      Height          =   285
      Left            =   3150
      TabIndex        =   7
      Top             =   2055
      Width           =   3375
   End
   Begin VB.TextBox txtgrupoespecifico 
      DataField       =   "grupo especifico"
      DataMember      =   "producto"
      DataSource      =   "d"
      Height          =   285
      Left            =   3150
      TabIndex        =   5
      Top             =   1675
      Width           =   3375
   End
   Begin VB.TextBox txtgrupoproducto 
      DataField       =   "grupo producto"
      DataMember      =   "producto"
      DataSource      =   "d"
      Height          =   285
      Left            =   3150
      TabIndex        =   3
      Top             =   1295
      Width           =   3375
   End
   Begin VB.TextBox txtcodigo 
      DataField       =   "codigo"
      DataMember      =   "producto"
      DataSource      =   "d"
      Height          =   285
      Left            =   3150
      TabIndex        =   1
      Top             =   915
      Width           =   3375
   End
   Begin MSHierarchicalFlexGridLib.MSHFlexGrid MSHFlexGrid1 
      Bindings        =   "Form1.frx":0000
      Height          =   3495
      Left            =   1320
      TabIndex        =   8
      Top             =   2520
      Width           =   4935
      _ExtentX        =   8705
      _ExtentY        =   6165
      _Version        =   393216
      Cols            =   5
      FixedCols       =   0
      AllowUserResizing=   3
      DataMember      =   "compras"
      _NumberOfBands  =   1
      _Band(0).Cols   =   5
      _Band(0).GridLinesBand=   1
      _Band(0).TextStyleBand=   0
      _Band(0).TextStyleHeader=   0
      _Band(0)._NumMapCols=   7
      _Band(0)._MapCol(0)._Name=   "id produc"
      _Band(0)._MapCol(0)._RSIndex=   0
      _Band(0)._MapCol(0)._Alignment=   7
      _Band(0)._MapCol(0)._Hidden=   -1  'True
      _Band(0)._MapCol(1)._Name=   "tipo de documento"
      _Band(0)._MapCol(1)._RSIndex=   1
      _Band(0)._MapCol(2)._Name=   "numero de documento"
      _Band(0)._MapCol(2)._RSIndex=   2
      _Band(0)._MapCol(2)._Alignment=   7
      _Band(0)._MapCol(3)._Name=   "cant compr"
      _Band(0)._MapCol(3)._RSIndex=   3
      _Band(0)._MapCol(3)._Alignment=   7
      _Band(0)._MapCol(4)._Name=   "precio total soles lima"
      _Band(0)._MapCol(4)._RSIndex=   4
      _Band(0)._MapCol(4)._Alignment=   7
      _Band(0)._MapCol(5)._Name=   "fecha de compr"
      _Band(0)._MapCol(5)._RSIndex=   5
      _Band(0)._MapCol(6)._Name=   "codigo"
      _Band(0)._MapCol(6)._RSIndex=   6
      _Band(0)._MapCol(6)._Hidden=   -1  'True
   End
   Begin VB.Label lblFieldLabel 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "unidad:"
      Height          =   255
      Index           =   3
      Left            =   1305
      TabIndex        =   6
      Top             =   2100
      Width           =   1815
   End
   Begin VB.Label lblFieldLabel 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "grupo especifico:"
      Height          =   255
      Index           =   2
      Left            =   1305
      TabIndex        =   4
      Top             =   1720
      Width           =   1815
   End
   Begin VB.Label lblFieldLabel 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "grupo producto:"
      Height          =   255
      Index           =   1
      Left            =   1305
      TabIndex        =   2
      Top             =   1340
      Width           =   1815
   End
   Begin VB.Label lblFieldLabel 
      Alignment       =   1  'Right Justify
      AutoSize        =   -1  'True
      Caption         =   "codigo:"
      Height          =   255
      Index           =   0
      Left            =   1305
      TabIndex        =   0
      Top             =   960
      Width           =   1815
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
d.rsproducto.MoveFirst

End Sub

Private Sub Command2_Click()
d.rsproducto.MovePrevious

End Sub

Private Sub Command3_Click()
d.rsproducto.MoveNext

End Sub

Private Sub Command4_Click()
d.rsproducto.MoveLast

End Sub
