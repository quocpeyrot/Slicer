/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLColorTableStorageNode.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.8 $

=========================================================================auto=*/

#ifndef __vtkMRMLColorTableStorageNode_h
#define __vtkMRMLColorTableStorageNode_h

#include "vtkMRMLStorageNode.h"

/// \brief MRML node for representing a volume storage.
///
/// vtkMRMLColorTableStorageNode nodes describe the archetybe based volume storage
/// node that allows to read/write volume data from/to file using generic ITK mechanism.
class VTK_MRML_EXPORT vtkMRMLColorTableStorageNode : public vtkMRMLStorageNode
{
  public:
  static vtkMRMLColorTableStorageNode *New();
  vtkTypeMacro(vtkMRMLColorTableStorageNode,vtkMRMLStorageNode);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  virtual vtkMRMLNode* CreateNodeInstance() VTK_OVERRIDE;

  /// Get node XML tag name (like Storage, Model)
  virtual const char* GetNodeTagName() VTK_OVERRIDE  {return "ColorTableStorage";};

  /// Return true if the node can be read in
  virtual bool CanReadInReferenceNode(vtkMRMLNode* refNode) VTK_OVERRIDE;

protected:
  vtkMRMLColorTableStorageNode();
  ~vtkMRMLColorTableStorageNode();
  vtkMRMLColorTableStorageNode(const vtkMRMLColorTableStorageNode&);
  void operator=(const vtkMRMLColorTableStorageNode&);

  /// Initialize all the supported read file types
  virtual void InitializeSupportedReadFileTypes() VTK_OVERRIDE;

  /// Initialize all the supported write file types
  virtual void InitializeSupportedWriteFileTypes() VTK_OVERRIDE;

  /// Read data and set it in the referenced node
  virtual int ReadDataInternal(vtkMRMLNode *refNode) VTK_OVERRIDE;

  /// Write data from a  referenced node
  virtual int WriteDataInternal(vtkMRMLNode *refNode) VTK_OVERRIDE;

  /// maximum valid number of colours to read in
  int MaximumColorID;

};

#endif



