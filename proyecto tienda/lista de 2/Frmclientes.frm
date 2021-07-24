VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Object = "{F0D2F211-CCB0-11D0-A316-00AA00688B10}#1.0#0"; "MSDATLST.OCX"
Begin VB.Form Frmcliente 
   Caption         =   "Clientes"
   ClientHeight    =   3300
   ClientLeft      =   2265
   ClientTop       =   1800
   ClientWidth     =   5025
   BeginProperty Font 
      Name            =   "Comic Sans MS"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Frmclientes.frx":0000
   LinkTopic       =   "Form1"
   Picture         =   "Frmclientes.frx":000C
   ScaleHeight     =   3300
   ScaleWidth      =   5025
   StartUpPosition =   2  'CenterScreen
   Begin VB.TextBox txtTelefono 
      Appearance      =   0  'Flat
      DataField       =   "Teléfono"
      DataSource      =   "adoClientes"
      Height          =   285
      Left            =   960
      Locked          =   -1  'True
      TabIndex        =   8
      Top             =   1920
      Width           =   1575
   End
   Begin VB.TextBox txtPais 
      Appearance      =   0  'Flat
      DataField       =   "País"
      DataSource      =   "adoClientes"
      Height          =   285
      Left            =   3360
      Locked          =   -1  'True
      TabIndex        =   7
      Top             =   1920
      Width           =   1575
   End
   Begin VB.TextBox txtDireccion 
      Appearance      =   0  'Flat
      DataField       =   "Dirección"
      DataSource      =   "adoClientes"
      Height          =   285
      Left            =   960
      Locked          =   -1  'True
      TabIndex        =   6
      Top             =   1560
      Width           =   3975
   End
   Begin VB.TextBox txtNombre 
      Appearance      =   0  'Flat
      DataField       =   "NombreCompañía"
      DataSource      =   "adoClientes"
      Height          =   285
      Left            =   960
      Locked          =   -1  'True
      TabIndex        =   5
      Top             =   1200
      Width           =   3975
   End
   Begin VB.TextBox txtCodigo 
      Appearance      =   0  'Flat
      DataField       =   "IdCliente"
      DataSource      =   "adoClientes"
      Height          =   285
      Left            =   960
      Locked          =   -1  'True
      TabIndex        =   4
      Top             =   840
      Width           =   1095
   End
   Begin VB.CommandButton CmdPedidos 
      Caption         =   "Pedidos"
      Height          =   330
      Left            =   3000
      Picture         =   "Frmclientes.frx":770F
      TabIndex        =   1
      Top             =   2400
      Width           =   930
   End
   Begin VB.CommandButton CmdSalir 
      Caption         =   "&Salir"
      Height          =   330
      Left            =   3960
      Picture         =   "Frmclientes.frx":C38B
      TabIndex        =   0
      Top             =   2400
      Width           =   930
   End
   Begin MSDataListLib.DataCombo dtcCliente 
      Bindings        =   "Frmclientes.frx":11007
      DataSource      =   "(Ninguno)"
      Height          =   345
      Left            =   120
      TabIndex        =   2
      Top             =   360
      Width           =   4815
      _ExtentX        =   8493
      _ExtentY        =   609
      _Version        =   393216
      Appearance      =   0
      Style           =   2
      ListField       =   "NombreCompañía"
      BoundColumn     =   "IdCliente"
      Text            =   ""
   End
   Begin MSAdodcLib.Adodc adoClientes 
      Height          =   330
      Left            =   120
      Top             =   2880
      Width           =   4815
      _ExtentX        =   8493
      _ExtentY        =   582
      ConnectMode     =   0
      CursorLocation  =   3
      IsolationLevel  =   -1
      ConnectionTimeout=   15
      CommandTimeout  =   30
      CursorType      =   3
      LockType        =   3
      CommandType     =   2
      CursorOptions   =   0
      CacheSize       =   50
      MaxRecords      =   0
      BOFAction       =   0
      EOFAction       =   0
      ConnectStringType=   1
      Appearance      =   0
      BackColor       =   -2147483643
      ForeColor       =   -2147483640
      Orientation     =   0
      Enabled         =   -1
      Connect         =   $"Frmclientes.frx":1102F
      OLEDBString     =   $"Frmclientes.frx":110BA
      OLEDBFile       =   ""
      DataSourceName  =   ""
      OtherAttributes =   ""
      UserName        =   ""
      Password        =   ""
      RecordSource    =   "Clientes"
      Caption         =   "Clientes"
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "Comic Sans MS"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _Version        =   393216
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Teléfono"
      Height          =   225
      Left            =   120
      TabIndex        =   13
      Top             =   1920
      Width           =   690
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "País"
      Height          =   225
      Left            =   2760
      TabIndex        =   12
      Top             =   1920
      Width           =   315
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Dirección"
      Height          =   225
      Left            =   120
      TabIndex        =   11
      Top             =   1560
      Width           =   765
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Nombre"
      Height          =   225
      Left            =   120
      TabIndex        =   10
      Top             =   1200
      Width           =   600
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Código:"
      Height          =   225
      Left            =   120
      TabIndex        =   9
      Top             =   840
      Width           =   570
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Seleccione un cliente"
      Height          =   225
      Left            =   120
      TabIndex        =   3
      Top             =   120
      Width           =   1650
   End
End
Attribute VB_Name = "Frmcliente"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public vFiltro As String

Private Sub Form_Load()
    adoClientes.Refresh
    dtcCliente.Text = adoClientes.Recordset(1)
End Sub

Private Sub dtcCliente_Click(Area As Integer)
    If dtcCliente.Text <> Empty Then
            adoClientes.Recordset.MoveFirst
            If adoClientes.Recordset.BOF Then Exit Sub
            If adoClientes.Recordset.EOF Then Exit Sub
            adoClientes.Recordset.Find "IdCliente ='" & Trim(dtcCliente.BoundText) & "'", 0, adSearchForward, 0
    End If
End Sub

Private Sub CmdPedidos_Click()
    vFiltro = dtcCliente.BoundText
    FrmPedidos.Show
End Sub

Private Sub CmdSalir_Click()
    End
End Sub

