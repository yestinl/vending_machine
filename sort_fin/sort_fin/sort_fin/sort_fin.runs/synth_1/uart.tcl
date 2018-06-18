# 
# Synthesis run script generated by Vivado
# 

set_param xicom.use_bs_reader 1
create_project -in_memory -part xc7a35tcsg324-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir D:/project/vivado/vending_machine/sort_fin/sort_fin/sort_fin/sort_fin.cache/wt [current_project]
set_property parent.project_path D:/project/vivado/vending_machine/sort_fin/sort_fin/sort_fin/sort_fin.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_output_repo d:/project/vivado/vending_machine/sort_fin/sort_fin/sort_fin/sort_fin.cache/ip [current_project]
set_property ip_cache_permissions {read write} [current_project]
read_verilog -library xil_defaultlib D:/project/vivado/vending_machine/sort_fin/sort_fin/sort_fin/sort_fin.srcs/sources_1/new/sortings.v
# Mark all dcp files as not used in implementation to prevent them from being
# stitched into the results of this synthesis run. Any black boxes in the
# design are intentionally left as such for best results. Dcp files will be
# stitched into the design at a later time, either when this synthesis run is
# opened, or when it is stitched into a dependent implementation run.
foreach dcp [get_files -quiet -all -filter file_type=="Design\ Checkpoint"] {
  set_property used_in_implementation false $dcp
}
read_xdc D:/project/vivado/vending_machine/sort_fin/sort_fin/sort_fin/sort_fin.srcs/constrs_1/new/pwm.xdc
set_property used_in_implementation false [get_files D:/project/vivado/vending_machine/sort_fin/sort_fin/sort_fin/sort_fin.srcs/constrs_1/new/pwm.xdc]


synth_design -top uart -part xc7a35tcsg324-1


write_checkpoint -force -noxdef uart.dcp

catch { report_utilization -file uart_utilization_synth.rpt -pb uart_utilization_synth.pb }
